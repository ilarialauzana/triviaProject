
#include "P_Map16x16.h"
#include "background.h"

//Declare the tiles emptyTile and fullTile as explained in the manual
u8 emptyTile[64] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 fullTile[64] =
{
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254,
	254,254,254,254,254,254,254,254
};


void P_Map16x16_configureBG2_Sub()
{
	BGCTRL_SUB[2] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(31) | BG_TILE_BASE(5);

	dmaCopy(emptyTile, (u8*)BG_TILE_RAM_SUB(5), 64);
	dmaCopy(fullTile, (u8*)BG_TILE_RAM_SUB(5) + 64, 64);

	BG_PALETTE_SUB[0] = ARGB16(1,12,22,12);
	BG_PALETTE_SUB[254] = ARGB16(1,16,26,16);
	BG_PALETTE_SUB[255] = ARGB16(1,0,0,0);

	mapMemory_sub = (u16*)BG_MAP_RAM_SUB(31);

}

void P_Map16x16_configureBG1()
{
	/*
	 * GRAPHICS III
	 *
	 * This function is called in the initialization of the P_Map16x16 to
	 * configure the Background 0 (on the top).
	 *
	 * This background is going to be used to draw the game field where
	 * the blocks are falling.
	 *
	 * The function does not return anything and it does not have any input
	 * arguments. Background 0 (BG0) should be configured in the tiled mode
	 * as a 32x32 tile grid and using one general color palette of 256
	 * components (256 colors). The pointer to the map 'mapMemory' must be
	 * correctly assigned before returning from the function
	 */

	//Configure BG 0 to represent the game field
	BGCTRL[1] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(18) | BG_TILE_BASE(1);

	//Copy the empty tile and the full tile to the corresponding RAM location
	//according to the chosen TILE_BASE. If dmaCopy is used, do not forget to
	//cast the destination pointer as a 'byte pointer'
	//Hint: Use the macro BG_TILE_RAM to get the destination address
	dmaCopy(emptyTile, (u8*)BG_TILE_RAM(1), 64);
	dmaCopy(fullTile, (u8*)BG_TILE_RAM(1)+64, 64);

	BG_PALETTE[254] = ARGB16(1,16,26,16);
	BG_PALETTE[0] = ARGB16(0,0,0,0);
	BG_PALETTE[255] = ARGB16(1,0,0,0);

	//Set the pointer mapMemory to the RAM location of the chosen MAP_BASE
	//Hint: use the macro BG_MAP_RAM
	mapMemory = (u16*)BG_MAP_RAM(18);

}

void P_Map16x16_configureBG3()
{
	/*GRAPHICS III
	 *
	 * This function is called in the initialization of the P_Map16x16 to
	 * configure the Background 3.
	 *
	 * This background is going to be used to background wall-paper.
	 *
	 * In exercise 2 the Background 3 (BG3) should be configure in rotoscale
	 * mode with a 8 bits of pixel depth. Do not forget to copy the palette
	 * correctly.
	 *
	 * In exercise 5 Background 3 (BG3) should be configured in the tiled mode
	 * as a 32x32 tile grid and using one general color palette of 256
	 * components (256 colors).
	 */

	//Configure BG 3 for the background image as explained before
	BGCTRL[3] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(16) | BG_TILE_BASE(3);

	//Copy tiles, map and palette in the memory (use swicopy or memcpy)
	dmaCopy(backgroundTiles, BG_TILE_RAM(3), backgroundTilesLen);
	dmaCopy(backgroundMap, BG_MAP_RAM(16), backgroundMapLen);
	dmaCopy(backgroundPal, BG_PALETTE, backgroundPalLen);

}

void P_Map16x16_Init( int cols, int rows )
{
    MapCols=cols;
    MapRows=rows;
#ifdef ROTOSCALE
    //Configure BG2
    P_Map16x16_configureBG2();
    // Configure Bottom background
    P_Map16x16_configureBG2_Sub();
#endif

#ifdef TILES
    //Configure BG3 for background image
    P_Map16x16_configureBG3();
    //Configure BG0 for game
    P_Map16x16_configureBG1();
    // Configure Bottom background
    P_Map16x16_configureBG2_Sub();
#endif
}


 void SetMap16x16To(int index16, bool full)
 {
	    //switch x and y
	    int x = index16 % MapCols;
	    int y = index16 / MapCols;
	    //now inverse x
	    y = -(y-MapRows+1);
	    index16 = x * MapRows + y;
#ifdef FB0
	    u16 value = full ? RGB15(31,0,0) : RGB15(0,0,0);
	    FillRectangle(MAIN,x*16, x*16+16, y*16, y*16+16,value);
#endif

#ifdef ROTOSCALE
	    u16 value = full ? ARGB16(1,31,0,0) : ARGB16(1,0,0,0);
	    FillRectangle(MAIN,x*16, x*16+16, y*16, y*16+16,value);
#endif
/*
#ifdef TILES
    int value = full ? 1 : 0;
    //convert index16x16 to 32x32
    //also make it fall right->left rather than top->bottom
    //
    //  0  1  2  3     12  8  4  0
    //  4  5  6  7  => 13  9  5  1
    //  8  9 10 11  => 14 10  6  2
    // 12 13 14 15     15 11  7  3

    //16x16->32*32 CONVERSION
    int index32;
    index32 =  index16*2;
    index32 += (index16/16)*32;
    mapMemory[index32] = value;
    mapMemory[index32+1] = value;
    mapMemory[index32+32] = value;
    mapMemory[index32+32+1] = value;
#endif*/
}
