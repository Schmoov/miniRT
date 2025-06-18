from PIL import Image
import numpy as np

def convert_to_custom_ascii_format(image_path, output_path):
    # Load image and convert to grayscale (L = 8-bit pixels, black and white)
    img = Image.open(image_path).convert('L')
    
    # Get dimensions
    width, height = img.size
    print(f"Image size: {height} rows x {width} cols")

    # Convert image data to numpy array
    data = np.asarray(img)

    # Write to output file
    with open(output_path, 'w') as f:
        f.write(f"{height} {width}\n")  # nb_rows nb_cols
        for row in data:
            reversed_row = row[::-1]
            f.write(' '.join(map(str, reversed_row)) + '\n')

# Example usage
convert_to_custom_ascii_format('World.png', '../bumpmap/earth.bump')

