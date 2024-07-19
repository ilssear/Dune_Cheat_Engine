# Decoder for Cheat Engine v7.5 Cheat Tables

import zlib
import os
import xml.etree.ElementTree as ET
from lxml import etree
import logging
from ct_common import (OUTPUT_PATH, LUA_PATH, CT_PATH, TRAINER_XML_PATH, FILES_ORDER, 
                       decode_ce_base85, ensure_directory_exists)

# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def process_trainer_xml(output_path: str, trainer_xml: ET.Element) -> None:
    """Process and save form files from the trainer XML.

    Args:
        output_path (str): Path to save the decoded files.
        trainer_xml (ET.Element): Root element of the trainer XML.
    """
    forms = trainer_xml.find('Files')
    if forms is not None:
        for i, val in enumerate(forms):
            if val.attrib.get('Encoding') != 'Ascii85':
                logging.error('Invalid Form encoding')
                continue
            form_data = zlib.decompress(decode_ce_base85(val.text), -zlib.MAX_WBITS)
            file_name = val.tag
            file_size = int.from_bytes(form_data[:4], byteorder='little')
            actual_data = form_data[4:]
            file_path = os.path.join(output_path, file_name)
            if not os.path.exists(file_path):
                with open(file_path, 'wb') as f:
                    f.write(actual_data)
                logging.info(f"File: {file_name}, Size: {file_size}, Actual Size: {len(actual_data)} saved to {file_path}")
            else:
                logging.warning(f"[SKIPPED] file exists: {file_name}")

def process_lua_scripts(lua_path: str, trainer_xml: ET.Element) -> None:
    """Process and save Lua scripts from the trainer XML.

    Args:
        lua_path (str): Path to save the Lua scripts.
        trainer_xml (ET.Element): Root element of the trainer XML.
    """
    lua_scripts = trainer_xml.find('LuaScript')
    if lua_scripts is not None:
        order = []
        for script_entry in lua_scripts.findall('LuaScriptEntry'):
            script_name = script_entry.attrib['Name']
            script_text = script_entry.text
            file_path = os.path.join(lua_path, f"{script_name}.lua")
            order.append(script_name)
            if not os.path.exists(file_path):
                with open(file_path, 'w') as f:
                    f.write(script_text)
                logging.info(f"Lua Script: {script_name} saved to {file_path}")
            else:
                logging.warning(f"[SKIPPED] file exists: {script_name}.lua")

        # Save the order of LuaScriptEntry names
        order_xml = etree.Element('LuaScriptsOrder')
        for script_name in order:
            etree.SubElement(order_xml, 'Script').text = script_name

        order_tree = etree.ElementTree(order_xml)
        pretty_xml = etree.tostring(order_tree, pretty_print=True, encoding='utf-8', xml_declaration=True).decode('utf-8')

        with open(FILES_ORDER, 'w', encoding='utf-8') as f:
            f.write(pretty_xml)
        logging.info(f"Order of Lua scripts saved to {FILES_ORDER}")

def save_cheat_table(ct_path: str, trainer_xml: ET.Element) -> None:
    """Save the remaining parts of the trainer XML as a Cheat Table.

    Args:
        ct_path (str): Path to save the Cheat Table XML.
        trainer_xml (ET.Element): Root element of the trainer XML.
    """
    if not os.path.exists(ct_path):
        for elem in trainer_xml.findall('Files'):
            trainer_xml.remove(elem)
        for elem in trainer_xml.findall('LuaScript'):
            trainer_xml.remove(elem)
        
        tree = ET.ElementTree(trainer_xml)
        tree.write(ct_path)
        logging.info(f"Cheat Table XML saved to {ct_path}")
    else:
        logging.warning(f"[SKIPPED] file exists: {ct_path}")

def main() -> None:
    """Main function to process the trainer XML and save its components."""
    ensure_directory_exists(OUTPUT_PATH)
    ensure_directory_exists(LUA_PATH)
    ensure_directory_exists(os.path.dirname(CT_PATH))

    tree = ET.parse(TRAINER_XML_PATH)
    root = tree.getroot()
    process_trainer_xml(OUTPUT_PATH, root)
    process_lua_scripts(LUA_PATH, root)
    save_cheat_table(CT_PATH, root)

if __name__ == "__main__":
    main()
