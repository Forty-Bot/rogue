#include <fxcg/display.h>
#include <fxcg/keyboard.h>

#include <stdlib.h>

#include "util.h"

#define MAP_WIDTH 48
#define MAP_HEIGHT 25

#define TILE_X 8
#define TILE_Y 8

#define SCR_WIDTH LCD_WIDTH_PX/TILE_X
#define SCR_HEIGHT LCD_HEIGHT_PX/TILE_Y
#define MAP_Y_OFFSET 1 * (TILE_Y)



// The graphical representation of a tile
typedef struct tile {
	unsigned int bitwidth;		// Color depth of the tile
	color_t* pallate;		// Should be have the same length as 2^bitwidth
	const unsigned char* bits;	// The actual data
} tile;

// Placeholder floor tile
const unsigned char tile_floor_bits[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF};
color_t tile_floor_pallate[] = {COLOR_WHITE, COLOR_BLACK};
tile tile_floor = { 1, tile_floor_pallate, tile_floor_bits};

typedef struct item item;
struct item {
	item* next;		// Next item
	item* prev;		// Previous item

};

typedef struct mob {
	int x;			// Coordinates
	int y;
	/*
	TODO: Create mob structures
	intelligence* ai;
	inventory* inv;
	equipment* equ;
	statistics* stats;
	*/
} mob;

// Makes up the map
typedef struct cell {
	tile* tile;		// The 8x8 tile which is on this cell
	item* item_first;	// First of the items laying on this cell
	item* item_last;	// Last of the items laying on the cell
	mob* mob;		// Mob standing on this cell
} cell;

int cell_init(cell* c) {

	c->tile 		= NULL;
	c->item_first	= NULL;
	c->item_last	= NULL;
	c->mob		= NULL;
	return 0;

}


cell* map[MAP_WIDTH][MAP_HEIGHT];

// Initialiaze the game
int init() {
	
	// Create a blank map
	int i, j;
	for(i = 0; i < MAP_WIDTH; i++) {
		for(j = 0; j < MAP_HEIGHT; j++) {
			if(cell_init(map[i][j])) return -1;
			map[i][j]->tile = &tile_floor;
		}
	}
	return 0;

}

// Draw the map to the screen
int draw() {
	
	int i, j;
	for(i = 0; i < MAP_WIDTH; i++) {
		for(j = 0; j < MAP_HEIGHT; j++) {
			tile* t = map[i][j]->tile;
			CopySpriteNbit(t->bits, i * TILE_X, (j * TILE_Y) + MAP_Y_OFFSET, 8, 8, t->pallate, t->bitwidth);
		}
	}

	Bdisp_PutDisp_DD();
	return 0;
	
}

// Handle commands
int handle_input() {
	
	int key;
	while(1) {
		GetKey(&key);
		if(key) break;
	}
	// Do nothing
	return 0;

}

int main() {
	
	init();

	while(1) {
        	draw();
		handle_input();	
	}
	return 0;

}
