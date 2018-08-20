#include <stdint.h>
#include <hls_stream.h>
#include "ap_int.h"


using namespace hls;

// Resolution 640x400
#define COLS (640)
#define ROWS (480)


#define LINE_COLOR (0xDCDC00)//(220,220,0)
#define SYMBOL_COLOR (0x00DCDC) //(0,220,220)
#define BACKGROUND_COLOR (0x320032) //(50,0,50)


#define OFFSET_Y (3)
#define OFFSET_X (25)
#define LENGHT_SYMBOL (7)
#define SCALE_SPRITE (10)
#define SIZE_SPRITE (SCALE_SPRITE*LENGHT_SYMBOL)
#define REF_X (COLS/5)
#define REF_Y (ROWS/5)
#define LINE_WIDTH (5)

struct ap_axis{
	ap_uint<24> tdata;
	ap_uint<1> tlast;
	ap_uint<1> tuser;
};

typedef ap_axis data_t;

int generate_game(stream<data_t> &image_stream);


int create_image(ap_uint<10> posicion, stream<data_t> &image_stream);


#define SIZE 10


bool in_block(ap_uint<10> col,ap_uint<10> row,ap_uint<10> block_id);
