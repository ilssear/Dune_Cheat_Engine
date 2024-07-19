
import os
import zlib
import base64
from lxml import etree

# Define constants
SCRIPT_FILES_DIR = './ScriptFiles'
LUA_FILES_DIR = './LuaFiles'
CT_XML_PATH = './CheatTable/ct.xml'
OUTPUT_XML_PATH = 'encoded_scripts.CT'
FILES_ORDER_PATH = os.path.join(LUA_FILES_DIR, '_files_order.xml')

SORT_METHOD = 'extension'  # Default sort method can be 'extension' or 'name'


# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Ensure the directories exist
if not os.path.exists(SCRIPT_FILES_DIR):
    os.makedirs(SCRIPT_FILES_DIR)

if not os.path.exists(LUA_FILES_DIR):
    os.makedirs(LUA_FILES_DIR)

if not os.path.exists(os.path.dirname(CT_XML_PATH)):
    os.makedirs(os.path.dirname(CT_XML_PATH))

# Adapted character map for CE Base85
ce_base85_char_map = dict(zip(
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%()*+,-./:;=?@[]^_{}',
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~'
))

# Reverse map for encoding
reverse_ce_base85_char_map = {v: k for k, v in ce_base85_char_map.items()}

def decode_ce_base85(data):
    return base64.b85decode(''.join(ce_base85_char_map[v] for v in data))

def encode_ce_base85(data):
    base85_encoded = base64.b85encode(data).decode()
    return ''.join(reverse_ce_base85_char_map[v] for v in base85_encoded)

def compress_and_encode_file_with_size(file_path):
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

def literal_opposite(text):
    # Create a mapping for the opposite characters in the printable ASCII range
    ascii_printable = ''.join(chr(i) for i in range(32, 127))  # Printable ASCII characters
    opposite = {char: chr(158 - ord(char)) for char in ascii_printable}
    
    # Transform the text using the opposite mapping
    transformed = ''.join(opposite.get(char, char) for char in text)
    
    return transformed

def custom_sort_key(file_name):
    name, ext = os.path.splitext(file_name)
    # Convert extension to its literal opposite
    opposite_ext = literal_opposite(ext)
    # Return a tuple with the opposite extension for sorting and the name
    return (opposite_ext, name.lower())

def get_sorted_files(file_dir, sort_method):
    file_names = os.listdir(file_dir)
    if sort_method == 'name':
        return sorted(file_names)
    else:  # Default to 'extension'
        return sorted(file_names, key=custom_sort_key)

def create_encoded_xml_with_size(script_files_dir, lua_files_dir, ct_xml_path, output_xml_path, sort_method):
    root = etree.Element('CheatTable', CheatEngineTableVersion='42')
    files_element = etree.SubElement(root, 'Files')
    
    # Get sorted list of script files
    sorted_script_files = get_sorted_files(script_files_dir, sort_method)
    for file_name in sorted_script_files:
        file_path = os.path.join(script_files_dir, file_name)
        if os.path.isfile(file_path):
            encoded_data = compress_and_encode_file_with_size(file_path)
            file_element = etree.SubElement(files_element, file_name, Encoding='Ascii85')
            file_element.text = encoded_data
    
    # Add the Cheat Table XML content
    cheat_table_tree = etree.parse(ct_xml_path)
    cheat_table_root = cheat_table_tree.getroot()
    for elem in cheat_table_root:
        if elem.tag not in ['Files', 'LuaScript']:
            root.append(elem)
    
    # Add Lua scripts based on files_order.xml
    lua_scripts_element = etree.SubElement(root, 'LuaScript')
    
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
    
    # Change indentation
    etree.indent(root, space="  ")
    
    # Convert the ElementTree to a pretty-printed XML string
    rough_string = etree.tostring(root, pretty_print=True, encoding='utf-8', xml_declaration=True).decode('utf-8')
    
    with open(output_xml_path, 'w', encoding='utf-8') as f:
        f.write(rough_string)

def validate_encoded_xml(encoded_xml_path):
    tree = etree.parse(encoded_xml_path)
    root = tree.getroot()
    forms = root.find('Files')
    if forms is not None:
        for val in forms:
            assert (val.attrib['Encoding'] == 'Ascii85'), 'Invalid Form'
            encoded_text = val.text
            decoded_data = zlib.decompress(decode_ce_base85(encoded_text), -zlib.MAX_WBITS)
            file_name = val.tag
            file_size = int.from_bytes(decoded_data[:4], byteorder='little')
            actual_data = decoded_data[4:]
            actual_size = len(actual_data)
            if file_size != actual_size:
                print(f"Validation failed for {file_name}: expected size {file_size}, actual size {actual_size}")
                return False
            else:
                print(f"Validation succeeded for {file_name}: expected size {file_size}, actual size {actual_size}")
    print("Validation successful")
    return True

# Example usage
create_encoded_xml_with_size(SCRIPT_FILES_DIR, LUA_FILES_DIR, CT_XML_PATH, OUTPUT_XML_PATH, SORT_METHOD)
if validate_encoded_xml(OUTPUT_XML_PATH):
    print(f"Encoded XML saved to {OUTPUT_XML_PATH}")
else:
    print("Validation failed")
