

import zlib
import base64
import os
import xml.etree.ElementTree as ET

# Paths to files and folders
output_path = './ContainedFiles'
trainer_xml_path = 'D4X.03.001.R.CT'


# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Adapted character map for CE Base85
ce_base85_char_map = dict(zip(
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%()*+,-./:;=?@[]^_{}',
    '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~'
))

def decode_ce_base85(data):
    return base64.b85decode(''.join(ce_base85_char_map[v] for v in data))

def process_trainer_xml_for_byte_analysis(trainer_xml):
    forms = trainer_xml.find('Files')
    results = []
    if forms is not None:
        for val in forms:
            assert (val.attrib['Encoding'] == 'Ascii85'), 'Invalid Form'
            form_data = zlib.decompress(decode_ce_base85(val.text), -zlib.MAX_WBITS)
            file_name = val.tag
            first_4_bytes = form_data[:4]
            byte_values = [b for b in first_4_bytes]
            ascii_values = [chr(b) if 32 <= b <= 126 else '.' for b in first_4_bytes]  # Printable ASCII or '.'
            hex_values = [hex(b) for b in first_4_bytes]
            little_endian_value = int.from_bytes(first_4_bytes, byteorder='little')
            file_size = len(form_data) - 4  # Calculating the file size as length of form_data - 4
            results.append({
                'file_name': file_name,
                'first_4_bytes': list(first_4_bytes),
                'byte_values': byte_values,
                'ascii_values': ascii_values,
                'hex_values': hex_values,
                'little_endian_value': little_endian_value,
                'file_size': file_size
            })
    return results

def main():
    tree = ET.parse(trainer_xml_path)
    root = tree.getroot()
    return process_trainer_xml_for_byte_analysis(root)

# Run the analysis
byte_analysis_results = main()
import pandas as pd
df = pd.DataFrame(byte_analysis_results)

print("Byte Analysis Results:")
print(df)