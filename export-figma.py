import requests
import json
import sys

# ==============================================================================
# PLEASE FILL IN YOUR DETAILS HERE
# ==============================================================================
# 1. Get your API Key from Figma Settings > Personal access tokens
API_KEY = "figd_vqz9xMshPycW8dPspMSNFyUchimyRy1FOixgZA4T"

# 2. Get the File Key from your Figma file's URL
#    e.g., for https://www.figma.com/file/AbCdEfGh/My-Design, the key is "AbCdEfGh"
FILE_KEY = "9aBRIfUSPDFpnbTWSuxnOK"

# 3. Define the name of the output file
OUTPUT_FILENAME = "figma_analysis_output.txt"
# ==============================================================================


def get_figma_file_data(api_key, file_key):
    """Fetches the Figma file data from the API."""
    headers = {"X-Figma-Token": api_key}
    url = f"https://api.figma.com/v1/files/{file_key}"
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()  # Raises an exception for bad status codes (4xx or 5xx)
        return response.json()
    except requests.exceptions.HTTPError as err:
        if err.response.status_code == 403:
            print("Error: Forbidden. Please check your API Key.", file=sys.stderr)
        elif err.response.status_code == 404:
            print("Error: Not Found. Please check your File Key.", file=sys.stderr)
        else:
            print(f"HTTP Error occurred: {err}", file=sys.stderr)
        sys.exit(1)
    except requests.exceptions.RequestException as err:
        print(f"An error occurred during the request: {err}", file=sys.stderr)
        sys.exit(1)


def print_node_tree(node, output_file, indent=0):
    """Recursively prints a simplified tree of the Figma nodes to a file."""
    prefix = "  " * indent
    node_type = node.get('type', 'UNKNOWN')
    node_name = node.get('name', 'Unnamed')
    
    # Print basic node info to the file
    print(f"{prefix}- [{node_type}] {node_name}", file=output_file)
    
    # If the node is a text layer, print its content
    if node_type == 'TEXT':
        text_content = node.get('characters', '').replace('\n', '\\n')
        print(f"{prefix}  - Content: \"{text_content}\"", file=output_file)

    # If the node is an instance of a component, show which component
    if node_type == 'INSTANCE':
        component_id = node.get('componentId')
        if component_id:
             print(f"{prefix}  - Instance of component ID: {component_id}", file=output_file)

    # Recurse into children
    if 'children' in node and isinstance(node['children'], list):
        for child in node['children']:
            print_node_tree(child, output_file, indent + 1)


def analyze_figma_file(data, output_file):
    """Parses and prints the structured analysis of the Figma file."""
    
    print("=" * 60, file=output_file)
    print(f"ANALYSIS FOR FIGMA FILE: {data.get('name', 'Untitled')}", file=output_file)
    print("=" * 60, file=output_file)

    # --- 1. Print Defined Components ---
    print("\n\n" + "#" * 60, file=output_file)
    print("## DEFINED COMPONENTS", file=output_file)
    print("#" * 60, file=output_file)
    components = data.get('components', {})
    if not components:
        print("No components defined in this file.", file=output_file)
    else:
        for component_id, component_info in components.items():
            print(f"\n- Component: {component_info['name']}", file=output_file)
            print(f"  - ID: {component_id}", file=output_file)
            description = component_info.get('description')
            if description:
                print(f"  - Description: {description}", file=output_file)

    # --- 2. Print Page and Frame Hierarchy ---
    print("\n\n" + "#" * 60, file=output_file)
    print("## PAGE & SCREEN HIERARCHY", file=output_file)
    print("#" * 60, file=output_file)
    document = data.get('document', {})
    if not document or 'children' not in document:
        print("Could not find document structure.", file=output_file)
        return

    for page in document['children']:
        if page.get('type') == 'CANVAS':
            print(f"\n\n{'='*20} PAGE: {page.get('name', 'Unnamed Page')} {'='*20}", file=output_file)
            if not page.get('children'):
                print("  (This page is empty)", file=output_file)
                continue
            
            # We are interested in top-level frames, which usually represent screens
            for screen_frame in page['children']:
                if screen_frame.get('type') in ['FRAME', 'GROUP', 'COMPONENT', 'COMPONENT_SET']:
                    print("\n" + "-" * 50, file=output_file)
                    print_node_tree(screen_frame, output_file)
                    print("-" * 50, file=output_file)


if __name__ == "__main__":
    if API_KEY == "YOUR_FIGMA_API_KEY" or FILE_KEY == "YOUR_FIGMA_FILE_KEY":
        print("ERROR: Please open the script and fill in your API_KEY and FILE_KEY.", file=sys.stderr)
        sys.exit(1)
        
    print("Fetching Figma file data... (This may take a moment)")
    figma_data = get_figma_file_data(API_KEY, FILE_KEY)
    
    print(f"Data received. Writing analysis to file: '{OUTPUT_FILENAME}'")
    try:
        # Open the output file with UTF-8 encoding to prevent errors
        with open(OUTPUT_FILENAME, "w", encoding="utf-8") as output_file:
            analyze_figma_file(figma_data, output_file)
        print(f"\nAnalysis complete. Please check the file '{OUTPUT_FILENAME}'.")
    except IOError as e:
        print(f"Error writing to file: {e}", file=sys.stderr)
        sys.exit(1)