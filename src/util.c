#include <fxcg/display.h>

#include "util.h"

void CopySpriteNbit(const unsigned char* data, int x, int y, int width, int height, color_t* palette, unsigned int bitwidth) {
	
	color_t* VRAM = (color_t*)0xA8000000;
	VRAM += (LCD_WIDTH_PX*y + x);
	int offset = 0;
	unsigned char buf;
	int i, j;
	for(j=y; j<y+height; j++) {
		int availbits = 0;
		for(i=x; i<x+width;	 i++) {
			if (!availbits) {
				buf = data[offset++];
				availbits = 8;
			}
			color_t this = ((color_t)buf>>(8-bitwidth));
			*VRAM = palette[(color_t)this];
			VRAM++;
			buf<<=bitwidth;
			availbits-=bitwidth;
		}
		VRAM += (LCD_WIDTH_PX-width);
	}

}
