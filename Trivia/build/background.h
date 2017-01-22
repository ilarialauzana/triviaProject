
//{{BLOCK(background)

//======================================================================
//
//	background, 256x256@8, 
//	+ palette 253 entries, not compressed
//	+ 1025 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 506 + 65600 + 2048 = 68154
//
//	Time-stamp: 2017-01-22, 14:40:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 65600
extern const unsigned int backgroundTiles[16400];

#define backgroundMapLen 2048
extern const unsigned short backgroundMap[1024];

#define backgroundPalLen 506
extern const unsigned short backgroundPal[254];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
