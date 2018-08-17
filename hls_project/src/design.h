#include <stdint.h>
#include <hls_stream.h>
#include "ap_int.h"


using namespace hls;

// Resolution 640x400
#define ROWS (640)
#define COLS (400)


#define LINE_COLOR (0xDCDC00)//(220,220,0)
#define SYMBOL_COLOR (0x00DCDC) //(0,220,220)
#define BACKGROUND_COLOR (0x320032) //(50,0,50)


struct ap_axis{
	ap_uint<24> tdata;
	ap_uint<1> tlast;
};

typedef ap_axis data_t;

int generate_game(stream<data_t> &image_stream);





#define SIZE 10

void gframe(int A[SIZE],int Q[SIZE]);
