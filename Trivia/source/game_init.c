#include "game_init.h"
#include <stdio.h>
#include <string.h>

PrintConsole pcMain;
PrintConsole pcSub;


void Gameplay_init(void) {
	int i,j;

	// Rectangle in touchscreen for "Name of player"
	for(i=23;i<31;i++)
		for(j=2;j<5;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,24,2,7,3);
	iprintf("Player\nName:\n%s", playerName);

	// Rectangles in touchscreen for "single player" and "multi player"
	for(i=2;i<14;i++)
		for(j=7;j<18;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,2,7,12,11);
	iprintf("\n\n\n\n   SINGLE\n\n   PLAYER");

	for(i=18;i<30;i++)
		for(j=7;j<18;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,18,7,12,11);
	iprintf("\n\n\n\n   MULTI\n\n   PLAYER");

	// Rectangle for scores
	for(i=10;i<22;i++)
		for(j=20;j<22;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,10,20,12,2);
	iprintf(" TOP SCORES");

	// Audio: song
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_MISS);
	mmStart(MOD_MISS,MM_PLAY_LOOP);

}

void Gameplay_Load(void) {
	int i,j;

	// Copy old palette (changed by consoleInit)
	u16 oldPal[16];
	for(i=0;i<16;i++){
		oldPal[i] = BG_PALETTE[15+i*16];
	}

	consoleInit(&pcSub,0,BgType_Text4bpp, BgSize_T_256x256, 4,0,false,true);
	consoleInit(&pcMain,0,BgType_Text4bpp, BgSize_T_256x256, 4,0,true,true);

	// Reset good palette (since changed by consoleInit)
	for(i=0;i<16;i++){
		BG_PALETTE[15+i*16] = oldPal[i];
	}

	// Create tiled rectangle for name of the game
	for(i=10;i<22;i++)
		for(j=6;j<18;j++)
			mapMemory[i+(j*32)] = 1;

	// Print name of the game
	consoleSetWindow(&pcMain,10,6,12,12);
	iprintf("\n\n  ARE YOU\n\n  SMARTER\n\n  THAN AN\n\n  ENGINEER?");

	// Get player name from storage
	FILE* f = fopen("/player.txt","w+");
	fscanf(f,"%s",playerName);

	if(strcmp(playerName,"") == 0){
		// Get name of the player, close keyboard and turn off layer 1
		playerName = getPlayer(&pcSub);
		keyboardHide();
		REG_DISPCNT_SUB &= ~(1 << 9);
		// Store name of player in memory
		fprintf(f,"%s",playerName);
		fclose(f);
	}

	// Start game
	Gameplay_init();
}

void Gameplay_restartGame(void) {
	//save score in memory

	Gameplay_init();
}

//change player : function to store new name in memory

