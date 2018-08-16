from PIL import Image


screen_res = (640,512)

line_color = (220,220,0)
symbol_color = (0,220,220)
background_color = (50,0,50)



xsymbol = [
    [1,1,0,0,0,1,1],
    [0,1,0,0,0,1,0],
    [0,1,1,0,1,1,0],
    [0,0,1,1,1,0,0],
    [0,1,1,0,1,1,0],
    [0,1,0,0,0,1,0],
    [1,1,0,0,0,1,1]
]

offy = 15
offx = 25
scale_sprite = 10
size_sprite = scale_sprite*len(xsymbol)

osymbol = [
    [0,0,1,1,1,0,0],
    [0,1,1,0,1,1,0],
    [1,1,0,0,0,1,1],
    [1,0,0,0,0,0,1],
    [1,1,0,0,0,1,1],
    [0,1,1,0,1,1,0],
    [0,0,1,1,1,0,0]
]



ref = (screen_res[0]//5,screen_res[1]//5)

line_width = 5
#   [(x0,   y0),    (X1,        y1)]
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

#   [(x0,   y0),    (X1,        y1)]

blocks = [
    [(ref[0]+line_width+offx,ref[1]+line_width+offy),(ref[0]+line_width+offx+size_sprite,ref[1]+line_width+offy+size_sprite)], #1 0,0
    [(ref[0]*2+line_width+offx,ref[1]+line_width+offy),(ref[0]*2+line_width+offx+size_sprite,ref[1]+line_width+offy+size_sprite)], #1 0,1
    [(ref[0]*3+line_width+offx,ref[1]+line_width+offy),(ref[0]*3+line_width+offx+size_sprite,ref[1]+line_width+offy+size_sprite)], #1 0,2

    [(ref[0]+line_width+offx,ref[1]*2+line_width+offy),(ref[0]+line_width+offx+size_sprite,ref[1]*2+line_width+offy+size_sprite)], #1 1,0
    [(ref[0]*2+line_width+offx,ref[1]*2+line_width+offy),(ref[0]*2+line_width+offx+size_sprite,ref[1]*2+line_width+offy+size_sprite)], #1 1,1
    [(ref[0]*3+line_width+offx,ref[1]*2+line_width+offy),(ref[0]*3+line_width+offx+size_sprite,ref[1]*2+line_width+offy+size_sprite)], #1 1,2

    [(ref[0]+line_width+offx,ref[1]*3+line_width+offy),(ref[0]+line_width+offx+size_sprite,ref[1]*3+line_width+offy+size_sprite)], #1 0,0
    [(ref[0]*2+line_width+offx,ref[1]*3+line_width+offy),(ref[0]*2+line_width+offx+size_sprite,ref[1]*3+line_width+offy+size_sprite)], #1 0,1
    [(ref[0]*3+line_width+offx,ref[1]*3+line_width+offy),(ref[0]*3+line_width+offx+size_sprite,ref[1]*3+line_width+offy+size_sprite)] #1 0,2
]

#print(lines)
def in_block(col,row,block):
    p0,p1 = block;
    return (p0[0]<=col) and (p0[1]<=row) and (p1[0]>=col) and (p1[1]>=row)

def check_lines(i,j,lines):
    for line in lines:
        if(in_block(i,j,line)):
            return True
    return False

#Board = [
#    [0,2,1],
#    [1,2,0],
#    [0,1,2]
#]

def check_blocks(i,j,blocks,Board):
    id=0
    block_val = 0
    for block in blocks:
        if(in_block(i,j,block)):
            block_val = Board[id//3][id%3]
            if(block_val==0):
                return False
            elif(block_val==1):
                pix = osymbol[ (j-block[0][1]-1)//(scale_sprite) ][ (i-block[0][0]-1)//(scale_sprite) ]
            else:
                pix = xsymbol[ (j-block[0][1]-1)//(scale_sprite) ][ (i-block[0][0]-1)//(scale_sprite) ]
            return True if(pix==1) else False
        id+=1
    return False

def create_image(Board):
	#print(ref)

	img = Image.new( 'RGB', (640,512), "black") # Create a new black image
	pixels = img.load() # Create the pixel map
	for i in range(img.size[0]):    # For every pixel:
		for j in range(img.size[1]):
			if(check_lines(i,j,lines)):
				pixels[i,j] = line_color;
			#elif(check_block):
			#    pixels[i,j] = xrgb[j%len(xrgb[0])][i%len(xrgb[0])];
			elif(check_blocks(i,j,blocks,Board)):
				pixels[i,j] = symbol_color
			else:
				pixels[i,j] = background_color # Set the colour accordingly
			if(i==ref[0] and j==ref[1]):
				pixels[i,j] = (255, 255, 255) # Set the colour accordingly

	img.show()
