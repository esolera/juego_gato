#include "design.h"

void gframe(int A[SIZE],int Q[SIZE])
{
// Si prefiere colocar un nombre "alias" al bus, puede colocar "bundle=NombreDelBus"
// Se utiliza register para capturar los datos del arreglo y almacenarlos en el IP Core
// La interface es AxiLite
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite register port=A
#pragma HLS INTERFACE s_axilite register port=B
#pragma HLS INTERFACE s_axilite register port=Q
	// Buffers
	int A_A[SIZE];
	int Q_A[SIZE];
	int i;
	// Load buffers
	for(i = 0; i < SIZE; i++)
	{
	//#pragma HLS PIPELINE
		A_A[i] = A[i];
	}

	// Operations
	for(i = 0; i < SIZE; i++)
	{
	//#pragma HLS PIPELINE
		Q_A[i] = A_A[i];
	}

	// Loading result
	for(i = 0; i < SIZE; i++)
	{
	//#pragma HLS PIPELINE
		Q[i] = Q_A[i];
	}
}


const ap_uint<1> xsymbol={
		{1,1,0,0,0,1,1},
		{0,1,0,0,0,1,0},
		{0,1,1,0,1,1,0},
		{0,0,1,1,1,0,0},
		{0,1,1,0,1,1,0},
		{0,1,0,0,0,1,0},
		{1,1,0,0,0,1,1}
};

const ap_uint<1> osymbol={
	    {0,0,1,1,1,0,0},
	    {0,1,1,0,1,1,0},
	    {1,1,0,0,0,1,1},
	    {1,0,0,0,0,0,1},
	    {1,1,0,0,0,1,1},
	    {0,1,1,0,1,1,0},
		{0,0,1,1,1,0,0}
};

ap_uint<8> Board = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
};

ap_uint<10> Lines = {
    {{REF_X,REF_Y},{REF_X*4,REF_Y+LINE_WIDTH}}, //1 ___
    {{REF_X,REF_Y*2},{REF_X*4,REF_Y*2+LINE_WIDTH}},  //2 ___
    {{REF_X,REF_Y*3},{REF_X*4,REF_Y*3+LINE_WIDTH}},  //3 ___
    {{REF_X,REF_Y*4},{REF_X*4,REF_Y*4+LINE_WIDTH}},  //4 ___
    {{REF_X,REF_Y},{REF_X+LINE_WIDTH,REF_Y*4}},  //1 |
    {{REF_X*2,REF_Y},{REF_X*2+LINE_WIDTH,REF_Y*4}},  //2 |
    {{REF_X*3,REF_Y},{REF_X*3+LINE_WIDTH,REF_Y*4}},  //4 |
    {{REF_X*4,REF_Y},{REF_X*4+LINE_WIDTH,REF_Y*4}} //#3 |
};

ap_uint<10> Blocks = {
    {{REF_X+LINE_WIDTH+OFFSET_X,REF_Y+LINE_WIDTH+OFFSET_Y},{OFFSET_X+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 0,0
    {{REF_X*2+LINE_WIDTH+OFFSET_X,REF_Y+LINE_WIDTH+OFFSET_Y},{OFFSET_X*2+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 0,1
    {{REF_X*3+LINE_WIDTH+OFFSET_X,REF_Y+LINE_WIDTH+OFFSET_Y},{OFFSET_X*3+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 0,2

    {{REF_X+LINE_WIDTH+OFFSET_X,REF_Y*2+LINE_WIDTH+OFFSET_Y},{OFFSET_X+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*2+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 1,0
    {{REF_X*2+LINE_WIDTH+OFFSET_X,REF_Y*2+LINE_WIDTH+OFFSET_Y},{OFFSET_X*2+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*2+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 1,1
    {{REF_X*3+LINE_WIDTH+OFFSET_X,REF_Y*2+LINE_WIDTH+OFFSET_Y},{OFFSET_X*3+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*2+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 1,2

    {{REF_X+LINE_WIDTH+OFFSET_X,REF_Y*3+LINE_WIDTH+OFFSET_Y},{OFFSET_X+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*3+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 0,0
    {{REF_X*2+LINE_WIDTH+OFFSET_X,REF_Y*3+LINE_WIDTH+OFFSET_Y},{OFFSET_X*2+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*3+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}}, //#1 0,1
    {{REF_X*3+LINE_WIDTH+OFFSET_X,REF_Y*3+LINE_WIDTH+OFFSET_Y},{OFFSET_X*3+LINE_WIDTH+OFFSET_X+SIZE_SPRITE,REF_Y*3+LINE_WIDTH+OFFSET_Y+SIZE_SPRITE}} //#1 0,2
};

//def in_block(col,row,block):
//    p0,p1 = block;
//    return (p0[0]<=col) and (p0[1]<=row) and (p1[0]>=col) and (p1[1]>=row)

bool in_block(ap_uint<10> col,ap_uint<10> row,ap_uint<10> block_id){
	ap_uint<10> p0[] = Blocks[block_id][0];
	ap_uint<10> p1[] = Blocks[block_id][1];
	return (p0[0]<=col) & (p0[1]<=row) & (p1[0]>=col) & (p1[1]>=row);
}




//def check_blocks(i,j,blocks,Board):
//    id=0
//    block_val = 0
//    for block in blocks:
//        if(in_block(i,j,block)):
//            block_val = Board[id//3][id%3]
//            if(block_val==0):
//                return False
//            elif(block_val==1):
//                pix = osymbol[ (j-block[0][1]-1)//(scale_sprite) ][ (i-block[0][0]-1)//(scale_sprite) ]
//            else:
//                pix = xsymbol[ (j-block[0][1]-1)//(scale_sprite) ][ (i-block[0][0]-1)//(scale_sprite) ]
//            return True if(pix==1) else False
//        id+=1
//	return False

bool check_blocks(ap_uint<10> col,ap_uint<10> row){
	ap_uint<10> id;
	ap_uint<10> block_val = 0;
	for(id=0;id<9;id++){
		if(in_block(col,row,id)){
			block_val = Board[id/3][id%3];
			switch(block_val){
			case 1:

					break;
			case 2:

					break;
			default:

			}
		}
	}
	return 0;
}


int generate_game(stream<data_t> &image_stream){
	
	data_t Pixel;
	for(int rows=0;rows<ROWS; rows++){
		for(int cols=0; cols<COLS; cols++){
			Pixel.tdata = BACKGROUND_COLOR;
			Pixel.tlast=false;
		}
		if(!(rows<(ROWS-1))){
			Pixel.tlast=true;
		}
		image_stream.write(Pixel);
	}

	return 0;
}

