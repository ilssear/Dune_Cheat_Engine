

import os
import xml.etree.ElementTree as ET
from xml.dom import minidom

# Paths to files and folders
output_path = 'D4X.04.001.R.pretty.xml'
# trainer_xml_path = 'D4X.04.001.R.xml'
# trainer_xml_path = 'D4X.04.001.R.pretty.v0.xml'
trainer_xml_path = 'sample.xml'


# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

"""
def prettify_xml(elem):
    # Return a pretty-printed XML string for the Element.
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    reparsed = reparsed.toprettyxml(indent="\t", newl="\n", encoding="utf-8").decode('utf-8')
    reparsed = '\n'.join([s for s in reparsed.splitlines() if s.strip()])
    return reparsed
"""

def prettify_xml(elem):
    """Return a pretty-printed XML string for the Element."""
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    pretty_xml = reparsed.toprettyxml(indent="\t", newl="\n", encoding="utf-8").decode('utf-8')
    
    # Remove extra newlines
    pretty_xml = '\n'.join([s for s in pretty_xml.splitlines() if s.strip()])
    
    # Custom handling for AssemblerScript tags
    lines = pretty_xml.split('\n')
    in_assembler_script = False
    assembler_script_content = []
    result_lines = []
    
    for line in lines:
        if '<AssemblerScript>' in line:
            in_assembler_script = True
            result_lines.append(line)
        elif '</AssemblerScript>' in line:
            in_assembler_script = False
            if assembler_script_content:
                # Indent the assembler script content
                indented_content = "\n".join(["\t\t" + l for l in assembler_script_content])
                result_lines.append(indented_content)
                assembler_script_content = []
            result_lines.append("\t" + line.strip())
        elif in_assembler_script:
            assembler_script_content.append(line.strip())
        else:
            result_lines.append(line)
    
    return '\n'.join(result_lines)


# dom = minidom.parse(trainer_xml_path) # or minidom.parseString(xml_string)
# pretty_xml_string = dom.toprettyxml(indent='  ', newl='\n', encoding=None, standalone=None)

dom = ET.parse(trainer_xml_path).getroot()

pretty_xml_string = prettify_xml(dom)

with open(output_path, 'w', encoding='utf-8') as f:
    f.write(pretty_xml_string)

