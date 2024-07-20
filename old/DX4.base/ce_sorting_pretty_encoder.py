# Encoder for Cheat Engine v7.5 Cheat Tables

import os
import zlib
import base64
from lxml import etree
import logging

# Define constants
SCRIPT_FILES_DIR = './ScriptFiles'
LUA_FILES_DIR = './LuaFiles'
CT_XML_PATH = './CheatTable/ct.xml'
OUTPUT_XML_PATH = 'encoded_scripts.CT'
FILES_ORDER_PATH = os.path.join(LUA_FILES_DIR, '_files_order.xml')
SORT_METHOD = 'extension'  # Default sort method can be 'extension' or 'name'

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Adapted character map for CE Base85
ce_base85_char_map = dict(zip(
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%()*+,-./:;=?@[]^_{}',
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~'
))

# Reverse map for encoding
reverse_ce_base85_char_map = {v: k for k, v in ce_base85_char_map.items()}

# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

def ensure_directory_exists(path: str) -> None:
    """Ensure the directory for the given path exists.

    Args:
        path (str): The directory path to check and create if it does not exist.
    """
    if not os.path.exists(path):
        os.makedirs(path)

def decode_ce_base85(data: str) -> bytes:
    """Decode Cheat Engine Base85 encoded data.

    Args:
        data (str): Base85 encoded string.

    Returns:
        bytes: Decoded bytes.
    """
    return base64.b85decode(''.join(ce_base85_char_map[v] for v in data))

def encode_ce_base85(data: bytes) -> str:
    """Encode data to Cheat Engine Base85 format.

    Args:
        data (bytes): Data to encode.

    Returns:
        str: Base85 encoded string.
    """
    base85_encoded = base64.b85encode(data).decode()
    return ''.join(reverse_ce_base85_char_map[v] for v in base85_encoded)

def compress_and_encode_file_with_size(file_path: str) -> str:
    """Compress and encode a file's contents, prepended with its size.

    Args:
        file_path (str): Path to the file to compress and encode.

    Returns:
        str: Compressed and Base85 encoded string.
    """
    with open(file_path, 'rb') as f:
        file_data = f.read()
    file_size = len(file_data)
    size_bytes = file_size.to_bytes(4, byteorder='little')
    padded_data = size_bytes + file_data
    comp_obj = zlib.compressobj(9, zlib.DEFLATED, wbits=-zlib.MAX_WBITS)
    compressed_data = comp_obj.compress(padded_data)
    compressed_data += comp_obj.flush()
    encoded_data = encode_ce_base85(compressed_data)
    return encoded_data

def literal_opposite(text: str) -> str:
    """Create the literal opposite of text based on printable ASCII characters.

    Args:
        text (str): Input text.

    Returns:
        str: Transformed text with opposite characters.
    """
    ascii_printable = ''.join(chr(i) for i in range(32, 127))  # Printable ASCII characters
    opposite = {char: chr(158 - ord(char)) for char in ascii_printable}
    transformed = ''.join(opposite.get(char, char) for char in text)
    return transformed

def custom_sort_key(file_name: str) -> tuple:
    """Generate a custom sort key for a file name based on its extension.

    Args:
        file_name (str): File name.

    Returns:
        tuple: A tuple containing the opposite extension and the file name.
    """
    name, ext = os.path.splitext(file_name)
    opposite_ext = literal_opposite(ext)
    return (opposite_ext, name.lower())

def get_sorted_files(file_dir: str, sort_method: str) -> list:
    """Get a sorted list of files from a directory.

    Args:
        file_dir (str): Directory containing the files.
        sort_method (str): Method to sort files ('name' or 'extension').

    Returns:
        list: Sorted list of file names.
    """
    file_names = os.listdir(file_dir)
    if sort_method == 'name':
        return sorted(file_names)
    else:  # Default to 'extension'
        return sorted(file_names, key=custom_sort_key)

def add_script_files_to_xml(files_element: etree.Element, script_files_dir: str, sort_method: str) -> None:
    """Add compressed and encoded script files to the XML element.

    Args:
        files_element (etree.Element): XML element to add the files to.
        script_files_dir (str): Directory containing the script files.
        sort_method (str): Method to sort files ('name' or 'extension').
    """
    sorted_script_files = get_sorted_files(script_files_dir, sort_method)
    for file_name in sorted_script_files:
        file_path = os.path.join(script_files_dir, file_name)
        if os.path.isfile(file_path):
            encoded_data = compress_and_encode_file_with_size(file_path)
            file_element = etree.SubElement(files_element, file_name, Encoding='Ascii85')
            file_element.text = encoded_data

def add_cheat_table_content(root: etree.Element, ct_xml_path: str) -> None:
    """Add content from the Cheat Table XML to the root element.

    Args:
        root (etree.Element): Root element of the final XML.
        ct_xml_path (str): Path to the Cheat Table XML file.
    """
    cheat_table_tree = etree.parse(ct_xml_path)
    cheat_table_root = cheat_table_tree.getroot()
    for elem in cheat_table_root:
        if elem.tag not in ['Files', 'LuaScript']:
            root.append(elem)

def add_lua_scripts_to_xml(lua_scripts_element: etree.Element, lua_files_dir: str) -> None:
    """Add Lua scripts to the XML element based on the order defined in files_order.xml.

    Args:
        lua_scripts_element (etree.Element): XML element to add the Lua scripts to.
        lua_files_dir (str): Directory containing the Lua files.
    """
    if os.path.exists(FILES_ORDER_PATH):
        order_tree = etree.parse(FILES_ORDER_PATH)
        order_root = order_tree.getroot()
        for script_elem in order_root.findall('Script'):
            script_name = script_elem.text
            file_path = os.path.join(lua_files_dir, f"{script_name}.lua")
            if os.path.isfile(file_path):
                with open(file_path, 'r', encoding='utf-8') as f:
                    script_text = f.read()
                script_element = etree.SubElement(lua_scripts_element, 'LuaScriptEntry', Name=script_name)
                script_element.text = script_text

def create_encoded_xml(script_files_dir: str, lua_files_dir: str, ct_xml_path: str, output_xml_path: str, sort_method: str) -> None:
    """Create an encoded XML with script and Lua files.

    Args:
        script_files_dir (str): Directory containing script files.
        lua_files_dir (str): Directory containing Lua files.
        ct_xml_path (str): Path to the Cheat Table XML file.
        output_xml_path (str): Path to save the encoded XML file.
        sort_method (str): Method to sort files ('name' or 'extension').
    """
    root = etree.Element('CheatTable', CheatEngineTableVersion='42')
    files_element = etree.SubElement(root, 'Files')
    add_script_files_to_xml(files_element, script_files_dir, sort_method)
    add_cheat_table_content(root, ct_xml_path)
    lua_scripts_element = etree.SubElement(root, 'LuaScript')
    add_lua_scripts_to_xml(lua_scripts_element, lua_files_dir)
    
    etree.indent(root, space="  ")
    rough_string = etree.tostring(root, pretty_print=True, encoding='utf-8', xml_declaration=True).decode('utf-8')
    
    with open(output_xml_path, 'w', encoding='utf-8') as f:
        f.write(rough_string)

def validate_encoded_xml(encoded_xml_path: str) -> bool:
    """Validate the encoded XML by checking the size of decompressed files.

    Args:
        encoded_xml_path (str): Path to the encoded XML file.

    Returns:
        bool: True if validation is successful, False otherwise.
    """
    tree = etree.parse(encoded_xml_path)
    root = tree.getroot()
    forms = root.find('Files')
    if forms is not None:
        for val in forms:
            if val.attrib.get('Encoding') != 'Ascii85':
                logging.error('Invalid Form encoding')
                return False
            encoded_text = val.text
            decoded_data = zlib.decompress(decode_ce_base85(encoded_text), -zlib.MAX_WBITS)
            file_name = val.tag
            file_size = int.from_bytes(decoded_data[:4], byteorder='little')
            actual_data = decoded_data[4:]
            actual_size = len(actual_data)
            if file_size != actual_size:
                logging.error(f"Validation failed for {file_name}: expected size {file_size}, actual size {actual_size}")
                return False
            logging.info(f"Validation succeeded for {file_name}: expected size {file_size}, actual size {actual_size}")
    logging.info("Validation successful")
    return True

def main() -> None:
    """Main function to create and validate encoded XML."""
    ensure_directory_exists(SCRIPT_FILES_DIR)
    ensure_directory_exists(LUA_FILES_DIR)
    ensure_directory_exists(os.path.dirname(CT_XML_PATH))
    
    create_encoded_xml(SCRIPT_FILES_DIR, LUA_FILES_DIR, CT_XML_PATH, OUTPUT_XML_PATH, SORT_METHOD)
    
    if validate_encoded_xml(OUTPUT_XML_PATH):
        logging.info(f"Encoded XML saved to {OUTPUT_XML_PATH}")
    else:
        logging.error("Validation failed")

if __name__ == "__main__":
    main()
