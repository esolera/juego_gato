#include <iostream>
#include "adder.h"
#include <iomanip>
#include <math.h>
using namespace std;

int main(void)
{
	// Variables
	float A[SIZE];
	float B[SIZE];
	float Q_hw[SIZE];
	float Q_sw[SIZE];
	int error = 0;

	// Generate seed
	for(int i = 0; i < SIZE; i++)
	{
		A[i] = 1.0*i;
		B[i] = 2.0*i;
		Q_sw[i] = A[i]+B[i];
	}
	// Send data
	adder(A, B, Q_hw);
	// Reveal data
	cout << "Data available:" << endl;
	for(int i = 0; i < SIZE; i++)
	{
		// Check delta
		float delta = Q_sw[i] - Q_hw[i];
		// Print values
		cout << "Software: " << Q_sw[i] << " Hardware: " << Q_hw[i] << " Delta: " << delta << endl;
		// Check delta
		if(fabs(delta) > 0.01) error++;
	}

	return error;
}
