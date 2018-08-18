#include <iostream>
#include "design.h"
#include <iomanip>
#include <math.h>
using namespace std;

ap_uint<10> posicion;
int main(void)
{


	ap_uint<10> posicion = 0;
	stream<data_t> image_stream;
	cout<< "Posicion " << posicion << endl;
	int ret = create_image(posicion, image_stream);
	if(ret!=0xFFFF){
		for ( int rows = 0; rows < 400; rows = rows + 1 ){
			for(int cols = 0; cols < 640; cols = cols + 1 ){
				image_stream.read().tdata;
			}
		}
	}
	while(!(ret==0x10 | ret==0x100)) {
		posicion = ((posicion+1)%9);
		cout<< "Posicion " << posicion << endl;
		ret = create_image(posicion, image_stream);
		if(ret!=0xFFFF){
			for ( int rows = 0; rows < 400; rows = rows + 1 ){
				for(int cols = 0; cols < 640; cols = cols + 1 ){
					cout <<"R: " <<rows <<"C: " <<cols << "D:" << image_stream.read().tdata<< endl;
				}
			}
		}
	}
	cout<< "RES FINALLL " << ret << endl;

}
