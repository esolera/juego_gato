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


const ap_int<1> xsymbol={
		{1,1,0,0,0,1,1},
		{0,1,0,0,0,1,0},
		{0,1,1,0,1,1,0},
		{0,0,1,1,1,0,0},
		{0,1,1,0,1,1,0},
		{0,1,0,0,0,1,0},
		{1,1,0,0,0,1,1}
};

const ap_int<1> osymbol={
	    {0,0,1,1,1,0,0},
	    {0,1,1,0,1,1,0},
	    {1,1,0,0,0,1,1},
	    {1,0,0,0,0,0,1},
	    {1,1,0,0,0,1,1},
	    {0,1,1,0,1,1,0},
		{0,0,1,1,1,0,0}
};



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

