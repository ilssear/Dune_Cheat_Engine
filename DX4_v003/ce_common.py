import os
import zlib
import base64
import logging
from lxml import etree

def read_config(config_file):
    """Read the configuration from the XML file and check for completeness.

    Args:
        config_file (str): Path to the configuration file.

    Returns:
        dict: Configuration dictionary if valid, None otherwise.
    """
    required_paths = ['trainer_xml_path', 'base_dir', 'base_files_dir', 'lua_files_dir',
                      'ct_xml_path', 'output_xml_path', 'files_order_path', 'custom_dir', 'custom_files_dirs']
    required_settings = ['sort_method']
    
    # Determine if the path is absolute or needs to be constructed relative to this file's directory
    if not os.path.isabs(config_file):
        config_file = os.path.join(os.path.dirname(__file__), config_file)
    
    try:
        tree = etree.parse(config_file)
        root = tree.getroot()
        
        config = {
            'paths': {
                'trainer_xml_path': root.findtext('paths/trainer_xml_path'),
                'base_dir': root.findtext('paths/base_dir'),
                'base_files_dir': root.findtext('paths/base_files_dir'),
                'lua_files_dir': root.findtext('paths/lua_files_dir'),
                'ct_xml_path': root.findtext('paths/ct_xml_path'),
                'output_xml_path': root.findtext('paths/output_xml_path'),
                'files_order_path': root.findtext('paths/files_order_path'),
                'custom_dir': root.findtext('paths/custom_dir'),
                'custom_files_dirs': [dir_elem.text for dir_elem in root.findall('paths/custom_files_dirs/dir')],
            },
            'settings': {
                'sort_method': root.findtext('settings/sort_method')
            }
        }

        # Check for completeness
        for path in required_paths:
            if not config['paths'].get(path):
                logging.error(f"Missing required path: {path}")
                return None
        
        for setting in required_settings:
            if not config['settings'].get(setting):
                logging.error(f"Missing required setting: {setting}")
                return None

        return config
    
    except Exception as e:
        logging.error(f"Error reading configuration file: {e}")
        logging.error("Please ensure the configuration file follows the correct format:")
        logging.error("""<?xml version="1.0" encoding="UTF-8"?>
<config>
    <paths>
        <trainer_xml_path>../compressed/DX.004.base.CT</trainer_xml_path>
        <base_dir>./DX4_base</base_dir>
        <base_files_dir>ScriptFiles</base_files_dir>
        <lua_files_dir>LuaFiles</lua_files_dir>
        <ct_xml_path>CheatTable</ct_xml_path>
        <output_xml_path>encoded_scripts.CT</output_xml_path>
        <files_order_path>_files_order.xml</files_order_path>
        <custom_dir>./DX4.001.R</custom_dir>
        <custom_files_dirs>
            <dir>C_Files</dir>
            <dir>ScriptFiles</dir>
        </custom_files_dirs>
    </paths>
    <settings>
        <sort_method>extension</sort_method>
    </settings>
</config>""")
        return None

# Adapted character map for CE Base85
ce_base85_char_map = dict(zip(
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%()*+,-./:;=?@[]^_{}',
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~'
))

# Reverse map for encoding
reverse_ce_base85_char_map = {v: k for k, v in ce_base85_char_map.items()}

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

def custom_sort_key(file_path: str) -> tuple:
    """Generate a custom sort key for a file name based on its extension.

    Args:
        file_path (str): File path.

    Returns:
        tuple: A tuple containing the opposite extension and the file name.
    """
    file_name = os.path.basename(file_path)
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
    full_paths = [os.path.join(file_dir, file_name) for file_name in file_names]

    if sort_method == 'name':
        return sorted(full_paths, key=os.path.basename)
    else:  # Default to 'extension'
        return sorted(full_paths, key=custom_sort_key)
