# Encoder for Cheat Engine v7.5 Cheat Tables

import os
import zlib
import base64
from lxml import etree
import logging
from ct_common import (SCRIPT_FILES_DIR, LUA_FILES_DIR, CT_XML_PATH, OUTPUT_XML_PATH, FILES_ORDER_PATH, 
                       SORT_METHOD, ce_base85_char_map, reverse_ce_base85_char_map, decode_ce_base85, 
                       encode_ce_base85, compress_and_encode_file_with_size, literal_opposite, 
                       get_sorted_files, ensure_directory_exists)

# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

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
