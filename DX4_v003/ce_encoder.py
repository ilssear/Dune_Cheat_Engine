# Encoder for Cheat Engine v7.5 Cheat Tables

import os
import zlib
from lxml import etree
import logging
import argparse
from ce_common import (read_config, decode_ce_base85, custom_sort_key, 
                       compress_and_encode_file_with_size)

# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def merge_files_dic(base_dir: str, custom_dir: str, sub_dirs: list or str) -> list: # type: ignore
    """Merge files from base and custom directories, with custom files taking precedence.

    Args:
        base_dir (str): Path to the base directory.
        custom_dir (str): Path to the custom directory.
        sub_dirs (list or str): Subdirectory or list of subdirectories to merge files from.

    Returns:
        list: List of full paths to merged files, with custom files taking precedence.
    """
    if isinstance(sub_dirs, str):
        sub_dirs = [sub_dirs]
    
    merged_files = {}
    
    for sub_dir in sub_dirs:
        base_path = os.path.join(base_dir, sub_dir)
        custom_path = os.path.join(custom_dir, sub_dir)
        
        if os.path.exists(base_path):
            base_files = {file: os.path.normpath(os.path.join(base_path, file)) for file in os.listdir(base_path)}
            merged_files.update(base_files)
        
        if os.path.exists(custom_path):
            custom_files = {file: os.path.normpath(os.path.join(custom_path, file)) for file in os.listdir(custom_path)}
            merged_files.update(custom_files)
    
    print("merged_files:\n", merged_files)
    
    return list(merged_files.values())

def add_script_files_to_xml(files_element: etree.Element, base_dir: str, custom_dir: str, custom_files_dirs: list, sort_method: str) -> None:
    """Add compressed and encoded script files to the XML element.

    Args:
        files_element (etree.Element): XML element to add the files to.
        base_dir (str): Path to the base directory.
        custom_dir (str): Path to the custom directory.
        custom_files_dirs (list): List of custom file directories.
        sort_method (str): Method to sort files ('name' or 'extension').
    """
    merged_files = merge_files_dic(base_dir, custom_dir, custom_files_dirs)
    
    if sort_method == 'name':
        sorted_script_files = sorted(merged_files, key=lambda x: os.path.basename(x).lower())
    else:  # Default to 'extension'
        sorted_script_files = sorted(merged_files, key=custom_sort_key)
    
    for file_path in sorted_script_files:
        file_name = os.path.basename(file_path)
        if os.path.isfile(file_path):
            encoded_data = compress_and_encode_file_with_size(file_path)
            file_element = etree.SubElement(files_element, file_name, Encoding='Ascii85')
            file_element.text = encoded_data

def add_cheat_table_content(root: etree.Element, base_dir: str, custom_dir: str, ct_xml_path: str) -> None:
    """Add content from the Cheat Table XML files to the root element.

    Args:
        root (etree.Element): Root element of the final XML.
        base_dir (str): Path to the base directory.
        custom_dir (str): Path to the custom directory.
        ct_xml_path (str): Path to the Cheat Table XML files.
    """
    base_xml_files = [f for f in os.listdir(os.path.join(base_dir, ct_xml_path)) if f.endswith('.xml')]
    custom_xml_files = [f for f in os.listdir(os.path.join(custom_dir, ct_xml_path)) if f.endswith('.xml')]
    all_xml_files = custom_xml_files + list(set(base_xml_files) - set(custom_xml_files))

    for file_name in all_xml_files:
        file_path = os.path.join(custom_dir, ct_xml_path, file_name) if file_name in custom_xml_files else os.path.join(base_dir, ct_xml_path, file_name)
        cheat_table_tree = etree.parse(file_path)
        cheat_table_root = cheat_table_tree.getroot()
        for elem in cheat_table_root:
            if elem.tag not in ['Files', 'LuaScript']:
                root.append(elem)

def merge_files_order(base_order_path: str, custom_order_path: str) -> list:
    """Merge file orders from base and custom order files.

    Args:
        base_order_path (str): Path to the base order XML file.
        custom_order_path (str): Path to the custom order XML file.

    Returns:
        list: Merged list of file orders.
    """
    custom_order = []
    base_order = []

    if os.path.exists(custom_order_path):
        custom_tree = etree.parse(custom_order_path)
        custom_root = custom_tree.getroot()
        custom_order = [elem.text for elem in custom_root.findall('Script')]

    if os.path.exists(base_order_path):
        base_tree = etree.parse(base_order_path)
        base_root = base_tree.getroot()
        base_order = [elem.text for elem in base_root.findall('Script')]

    # Custom order takes precedence, add base order items that are not in custom order
    merged_order = custom_order + [item for item in base_order if item not in custom_order]
    
    return merged_order

def add_lua_scripts_to_xml(lua_scripts_element: etree.Element, base_dir: str, custom_dir: str, lua_files_dir: str, files_order_path: str) -> None:
    """Add Lua scripts to the XML element based on the order defined in files_order.xml.

    Args:
        lua_scripts_element (etree.Element): XML element to add the Lua scripts to.
        base_dir (str): Path to the base directory.
        custom_dir (str): Path to the custom directory.
        lua_files_dir (str): Directory containing the Lua files.
        files_order_path (str): Path to the files order XML file.
    """
    base_order_path = os.path.join(base_dir, lua_files_dir, files_order_path)
    custom_order_path = os.path.join(custom_dir, lua_files_dir, files_order_path)

    merged_order = merge_files_order(base_order_path, custom_order_path)

    for script_name in merged_order:
        file_path = os.path.join(custom_dir, lua_files_dir, f"{script_name}.lua") if os.path.exists(os.path.join(custom_dir, lua_files_dir, f"{script_name}.lua")) else os.path.join(base_dir, lua_files_dir, f"{script_name}.lua")
        if os.path.isfile(file_path):
            with open(file_path, 'r', encoding='utf-8') as f:
                script_text = f.read()
            script_element = etree.SubElement(lua_scripts_element, 'LuaScriptEntry', Name=script_name)
            script_element.text = script_text

def create_encoded_xml(base_dir: str, custom_dir: str, output_xml_path: str, custom_files_dirs: list, lua_files_dir: str, files_order_path: str, ct_xml_path: str, sort_method: str) -> None:
    """Create an encoded XML with script and Lua files.

    Args:
        base_dir (str): Path to the base directory.
        custom_dir (str): Path to the custom directory.
        output_xml_path (str): Path to save the encoded XML file.
        custom_files_dirs (list): List of custom file directories.
        lua_files_dir (str): Directory containing the Lua files.
        files_order_path (str): Path to the files order XML file.
        ct_xml_path (str): Path to the Cheat Table XML files.
        sort_method (str): Method to sort files ('name' or 'extension').
    """
    root = etree.Element('CheatTable', CheatEngineTableVersion='42')
    files_element = etree.SubElement(root, 'Files')
    add_script_files_to_xml(files_element, base_dir, custom_dir, custom_files_dirs, sort_method)
    add_cheat_table_content(root, base_dir, custom_dir, ct_xml_path)
    lua_scripts_element = etree.SubElement(root, 'LuaScript')
    add_lua_scripts_to_xml(lua_scripts_element, base_dir, custom_dir, lua_files_dir, files_order_path)
    
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

def main(config_file: str) -> None:
    """Main function to create and validate encoded XML."""
    global BASE_DIR, CUSTOM_DIR, CUSTOM_FILES_DIRS, LUA_FILES_DIR, CT_XML_PATH, OUTPUT_XML_PATH, FILES_ORDER_PATH, SORT_METHOD
    config = read_config(config_file)
    if not config:
        logging.error("Failed to read config file.")
        return

    BASE_DIR = config['paths']['base_dir']
    CUSTOM_DIR = config['paths']['custom_dir']
    CUSTOM_FILES_DIRS = config['paths']['custom_files_dirs']
    LUA_FILES_DIR = config['paths']['lua_files_dir']
    CT_XML_PATH = config['paths']['ct_xml_path']
    OUTPUT_XML_PATH = config['paths']['output_xml_path']
    FILES_ORDER_PATH = config['paths']['files_order_path']
    SORT_METHOD = config['settings']['sort_method']

    create_encoded_xml(BASE_DIR, CUSTOM_DIR, OUTPUT_XML_PATH, CUSTOM_FILES_DIRS, LUA_FILES_DIR, FILES_ORDER_PATH, CT_XML_PATH, SORT_METHOD)
    
    if validate_encoded_xml(OUTPUT_XML_PATH):
        logging.info(f"Encoded XML saved to {OUTPUT_XML_PATH}")
    else:
        logging.error("Validation failed")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Encoder for Cheat Engine v7.5 Cheat Tables")
    parser.add_argument('-c', '--config', type=str, default='ce_config.xml', help='Path to the configuration file')
    args = parser.parse_args()
    main(args.config)
