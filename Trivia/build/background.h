
//{{BLOCK(background)

//======================================================================
//
//	background, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 1025 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 32800 + 2048 = 34880
//
//	Time-stamp: 2017-01-22, 11:49:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 32800
extern const unsigned int backgroundTiles[8200];

#define backgroundMapLen 2048
extern const unsigned short backgroundMap[1024];

#define backgroundPalLen 32
extern const unsigned short backgroundPal[16];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
