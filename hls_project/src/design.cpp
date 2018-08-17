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


int generate_game(stream<data_t> &image_stream){
	
	for(int i)

	return 0;
}

