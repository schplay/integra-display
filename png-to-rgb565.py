########################
# python convert_images.py path/to/image.png
#
# python convert_images.py path/to/folder
#
#
#
########################

import os
import sys
from PIL import Image

MAX_DIMENSION = 480

def resize_image(image):
    width, height = image.size
    if width > MAX_DIMENSION or height > MAX_DIMENSION:
        if width >= height:
            new_width = MAX_DIMENSION
            new_height = int((MAX_DIMENSION / width) * height)
        else:
            new_height = MAX_DIMENSION
            new_width = int((MAX_DIMENSION / height) * width)
        return image.resize((new_width, new_height), Image.LANCZOS)
    return image

def convert_to_rgb565(image):
    image = image.convert("RGB")
    pixels = list(image.getdata())
    rgb565_data = bytearray()
    for r, g, b in pixels:
        rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
        rgb565_data.append(rgb565 >> 8)
        rgb565_data.append(rgb565 & 0xFF)
    return rgb565_data

def save_with_header(filename, image, rgb565_data):
    width, height = image.size
    output_file = os.path.splitext(os.path.basename(filename))[0] + ".rgb565"
    output_path = os.path.join("converted", output_file)
    os.makedirs("converted", exist_ok=True)

    with open(output_path, "wb") as f:
        f.write(width.to_bytes(2, byteorder="little"))
        f.write(height.to_bytes(2, byteorder="little"))
        f.write(rgb565_data)
    print(f"Saved: {output_path}")

def process_image(file_path):
    try:
        image = Image.open(file_path)
        image = resize_image(image)
        rgb565_data = convert_to_rgb565(image)
        save_with_header(file_path, image, rgb565_data)
    except Exception as e:
        print(f"Failed to process {file_path}: {e}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python convert_images.py <image-file|folder>")
        return

    input_path = sys.argv[1]

    if os.path.isdir(input_path):
        for file in os.listdir(input_path):
            full_path = os.path.join(input_path, file)
            if file.lower().endswith((".png", ".jpg", ".jpeg")):
                process_image(full_path)
    elif os.path.isfile(input_path):
        process_image(input_path)
    else:
        print("Invalid file or folder.")

if __name__ == "__main__":
    main()
