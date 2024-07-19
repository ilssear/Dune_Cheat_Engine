# Common functions and constants for Cheat Engine v7.5 Cheat Table scripts

import os
import zlib
import base64

# Constants
OUTPUT_PATH = './ScriptFiles'
LUA_PATH = './LuaFiles'
CT_PATH = './CheatTable/ct.xml'
TRAINER_XML_PATH = '../compressed/D4X.04.002.R.CT'
FILES_ORDER = os.path.join(LUA_PATH, '_files_order.xml')
SCRIPT_FILES_DIR = 'ScriptFiles'
LUA_FILES_DIR = 'LuaFiles'
CT_XML_PATH = 'CheatTable/ct.xml'
OUTPUT_XML_PATH = 'encoded_scripts.CT'
FILES_ORDER_PATH = os.path.join(LUA_FILES_DIR, '_files_order.xml')
SORT_METHOD = 'extension'  # Default sort method can be 'extension' or 'name'


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
