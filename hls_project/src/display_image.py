from PIL import Image



xsymbol = [
    [1,0,1],
    [0,1,0],
    [1,0,1]
]

xrgb = [[((255,255,255) if (column == 1) else (0,0,0)) for column in line] for line in xsymbol]

img = Image.new( 'RGB', (640,512), "black") # Create a new black image
pixels = img.load() # Create the pixel map
for i in range(img.size[0]):    # For every pixel:
    for j in range(img.size[1]):
        pixels[i,j] = (0, 0, 0) # Set the colour accordingly

img.show()
