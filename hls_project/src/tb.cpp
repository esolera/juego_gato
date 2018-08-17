#include <iostream>
#include "design.h"
#include <iomanip>
#include <math.h>
using namespace std;

int main(void)
{
	// Variables
	int A[SIZE];
	int Q_hw[SIZE];
	int Q_sw[SIZE];
	int error = 0;

	// Generate seed
	for(int i = 0; i < SIZE; i++)
	{
		A[i] = 1.0*i;
		Q_sw[i] = A[i];
	}
	// Send data
	gframe(A, Q_hw);
	// Reveal data
	cout << "Data available:" << endl;
	for(int i = 0; i < SIZE; i++)
	{
		// Check delta
		int delta = Q_sw[i] - Q_hw[i];
		// Print values
		cout << "Software: " << Q_sw[i] << " Hardware: " << Q_hw[i] << " Delta: " << delta << endl;
		// Check delta
		if(delta > 0.01) error++;
	}

for ( int block = 0; block < 8; block = block + 1 ){
	for ( int rows = 0; rows < 400; rows = rows + 1 ){
		for(int cols = 0; cols < 640; cols = cols + 1 ){
			//cout << in_block(cols,rows,block)<< "  Col" << cols << " fil" << rows << " block" << block << endl;
			cout << in_block(cols,rows,block)<< endl;
		}
	}
}

	return error;
}
