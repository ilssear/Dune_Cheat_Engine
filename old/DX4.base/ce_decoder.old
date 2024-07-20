

import zlib
import base64
import os
import xml.etree.ElementTree as ET
from lxml import etree

# Paths to files and folders
output_path = './ScriptFiles'
lua_path = './LuaFiles'
ct_path = './CheatTable/ct.xml'
trainer_xml_path = '../compressed/D4X.04.002.R.CT'
files_order = os.path.join(lua_path, '_files_order.xml')

# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Ensure the output directories exist
if not os.path.exists(output_path):
    os.makedirs(output_path)

if not os.path.exists(lua_path):
    os.makedirs(lua_path)

if not os.path.exists(os.path.dirname(ct_path)):
    os.makedirs(os.path.dirname(ct_path))

# Adapted character map for CE Base85
ce_base85_char_map = dict(zip(
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%()*+,-./:;=?@[]^_{}',
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~'
))

def decode_ce_base85(data):
    return base64.b85decode(''.join(ce_base85_char_map[v] for v in data))

def process_trainer_xml(output_path, trainer_xml):
    forms = trainer_xml.find('Files')
    if forms is not None:
        for i, val in enumerate(forms):
            assert (val.attrib['Encoding'] == 'Ascii85'), 'Invalid Form'
            form_data = zlib.decompress(decode_ce_base85(val.text), -zlib.MAX_WBITS)
            file_name = val.tag
            file_size = int.from_bytes(form_data[:4], byteorder='little')
            actual_data = form_data[4:]
            actual_size = len(actual_data)
            file_path = os.path.join(output_path, file_name)
            if not os.path.exists(file_path):
                with open(file_path, 'wb') as f:
                    f.write(actual_data)
                print(f"File: {file_name}, Size: {file_size}, Actual Size: {actual_size} saved to {file_path}")
            else:
                print(f"[SKIPPED] file exists: {file_name}")

def process_lua_scripts(lua_path, trainer_xml):
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
                print(f"Lua Script: {script_name} saved to {file_path}")
            else:
                print(f"[SKIPPED] file exists: {script_name}.lua")

        # Save the order of LuaScriptEntry names
        order_xml = etree.Element('LuaScriptsOrder')
        for script_name in order:
            etree.SubElement(order_xml, 'Script').text = script_name

        order_tree = etree.ElementTree(order_xml)
        
        # Pretty print the XML
        pretty_xml = etree.tostring(order_tree, pretty_print=True, encoding='utf-8', xml_declaration=True).decode('utf-8')

        with open(files_order, 'w', encoding='utf-8') as f:
            f.write(pretty_xml)
        print(f"Order of Lua scripts saved to {files_order}")


def save_cheat_table(ct_path, trainer_xml):
    if not os.path.exists(ct_path):
        # Remove the <Files> and <LuaScript> sections to avoid duplication
        for elem in trainer_xml.findall('Files'):
            trainer_xml.remove(elem)
        for elem in trainer_xml.findall('LuaScript'):
            trainer_xml.remove(elem)
        
        # Write the remaining XML to the specified path
        tree = ET.ElementTree(trainer_xml)
        tree.write(ct_path)
        print(f"Cheat Table XML saved to {ct_path}")
    else:
        print(f"[SKIPPED] file exists: {ct_path}")

def main():
    tree = ET.parse(trainer_xml_path)
    root = tree.getroot()
    process_trainer_xml(output_path, root)
    process_lua_scripts(lua_path, root)
    save_cheat_table(ct_path, root)

if __name__ == "__main__":
    main()
