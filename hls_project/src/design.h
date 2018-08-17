#include <stdint.h>
#include <hls_stream.h>
#include "ap_int.h"


using namespace hls;




struct ap_axis{
	ap_uint<8> R;
	ap_uint<8> G;
	ap_uint<8> B;
	ap_uint<1> last;
};

typedef ap_axis data_t;

int generate_game(stream<data_t> &image_stream);

#define SIZE 10

void gframe(int A[SIZE],int Q[SIZE]);
