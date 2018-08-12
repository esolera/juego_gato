from PIL import Image


def symbolmap(symbol):
    return [[((255,255,255) if (column == 1) else (0,0,0)) for column in line] for line in symbol]

screen_res = (640,512)

line_color = (220,220,0)
background_color = (50,0,50)

xsymbol = [
    [1,0,1],
    [0,1,0],
    [1,0,1]
]

osymbol = [
    [0,1,0],
    [1,0,1],
    [0,1,0]
]

xrgb = symbolmap(xsymbol)
#[[((255,255,255) if (column == 1) else (0,0,0)) for column in line] for line in xsymbol]
orgb = symbolmap(osymbol)


ref = (screen_res[0]//5,screen_res[1]//5)

line_width = 5

lines = [
    [(ref[0],ref[1]),(ref[0]*4,ref[1]+line_width)], #1 ___
    [(ref[0],ref[1]*2),(ref[0]*4,ref[1]*2+line_width)],  #2 ___
    [(ref[0],ref[1]*3),(ref[0]*4,ref[1]*3+line_width)],  #3 ___
    [(ref[0],ref[1]*4),(ref[0]*4,ref[1]*4+line_width)],  #4 ___
    [(ref[0],ref[1]),(ref[0]+line_width,ref[1]*4)],  #1 |
    [(ref[0]*2,ref[1]),(ref[0]*2+line_width,ref[1]*4)],  #2 |
    [(ref[0]*3,ref[1]),(ref[0]*3+line_width,ref[1]*4)],  #4 |
    [(ref[0]*4,ref[1]),(ref[0]*4+line_width,ref[1]*4)]  #3 |
]


print(lines)
def in_block(row,col,block):
    p0,p1 = block;
    return (p0[0]<=row) and (p0[1]<=col) and (p1[0]>=row) and (p1[1]>=col)

def check_lines(cord,lines):
    for line in lines:
        if(in_block(i,j,line)):
            return True
    return False

print(ref)

img = Image.new( 'RGB', (640,512), "black") # Create a new black image
pixels = img.load() # Create the pixel map
for i in range(img.size[0]):    # For every pixel:
    for j in range(img.size[1]):
        if(check_lines((i,j),lines)):
            pixels[i,j] = line_color;
        #elif(check_block):
        #    pixels[i,j] = xrgb[j%len(xrgb[0])][i%len(xrgb[0])];
        else:
            pixels[i,j] = background_color # Set the colour accordingly
        if(i==ref[0] and j==ref[1]):
            pixels[i,j] = (255, 255, 255) # Set the colour accordingly

img.show()
