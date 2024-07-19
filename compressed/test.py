import os
import xml.etree.ElementTree as ET
from xml.dom import minidom
import re



# Change the working directory to the directory where the script resides
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

# Paths to files and folders
input_path = 'D4X.04.001b.R.CT'
output_path = 'pretty_ct.xml'


def prettify_xml(elem, indent='\t', newline='\n'):
    """Return a pretty-printed XML string for the Element."""
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    
    # Custom pretty printing function to handle node-by-node processing
    def remove_extra_newlines(node):
        if node.nodeType == node.TEXT_NODE:
            node.data = newline.join([line for line in node.data.splitlines() if line.strip()])
        for child in node.childNodes:
            if child.nodeType == node.ELEMENT_NODE and child.tagName == 'AssemblerScript':
                # Skip processing for AssemblerScript content
                continue
            remove_extra_newlines(child)
    
    # Apply the custom function
    remove_extra_newlines(reparsed)
    
    pretty_xml = reparsed.toprettyxml(indent=indent, newl=newline, encoding="utf-8").decode('utf-8')
    
    # Remove extra newlines introduced by toprettyxml
    pretty_xml = newline.join([s for s in pretty_xml.splitlines() if s.strip()])
    return pretty_xml

def pretty_print_ce_script(script):
    """Keep the code inside AssemblerScript tags unchanged."""
    return script.strip()

def format_and_replace_assembler_scripts(pretty_xml_string):
    """Extract, format, and replace AssemblerScript blocks in the given XML string."""
    # Extract and format AssemblerScript blocks
    pattern = re.compile(r'((\s*)<AssemblerScript>.*?</AssemblerScript>)', re.DOTALL)
    scripts = pattern.findall(pretty_xml_string)
    formatted_scripts = []
    
    for script, indentation in scripts:
        content = re.search(r'<AssemblerScript>(.*?)</AssemblerScript>', script, re.DOTALL).group(1).strip()
        formatted_content = pretty_print_ce_script(content)
        formatted_script = f"{indentation}<AssemblerScript>\n{formatted_content}\n{indentation}</AssemblerScript>"
        formatted_scripts.append(formatted_script)
    
    # Replace the original scripts with formatted ones
    for original, formatted in zip([script[0] for script in scripts], formatted_scripts):
        pretty_xml_string = pretty_xml_string.replace(original, formatted)
    
    return pretty_xml_string

def PrettyCT(xml_path, output_path, indent='\t', newline='\n'):
    """Prettify a Cheat Engine Table XML and replace AssemblerScript content with formatted indentation."""
    # Parse the input XML file
    dom = ET.parse(xml_path).getroot()
    
    # Generate the pretty XML string
    pretty_xml_string = prettify_xml(dom, indent, newline)
    
    # Format and replace AssemblerScript blocks
    pretty_xml_string = format_and_replace_assembler_scripts(pretty_xml_string)
    
    # Write the output to a new file
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(pretty_xml_string)

# Run PrettyCT on the input file
PrettyCT(input_path, output_path)