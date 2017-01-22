#include "game_init.h"
#include <stdio.h>

PrintConsole pcMain;
PrintConsole pcSub;

void Gameplay_init(void) {
	int i,j;

	consoleInit(&pcSub,0,BgType_Text8bpp, BgSize_T_256x256, 2,0,false,false);

	// Rectangle in touchscreen for "Name of player"
	for(i=24;i<31;i++)
		for(j=2;j<5;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,24,2,7,3);
	printf("Player Name:");

	// Rectangles in touchscreen for "single" and "multiplayer"
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

	// Rectangle for top score
	for(i=10;i<22;i++)
		for(j=20;j<22;j++)
			mapMemory_sub[i+(j*32)] = 1;

	consoleSetWindow(&pcSub,10,20,12,2);
	iprintf(" TOP SCORES");

	consoleInit(&pcMain,0,BgType_Text8bpp, BgSize_T_256x256, 2,0,true,false);

	// Name of the game
	for(i=10;i<22;i++)
		for(j=6;j<18;j++)
			mapMemory[i+(j*32)] = 1;

	consoleSetWindow(&pcMain,10,6,12,12);
	iprintf("\n\n  ARE YOU\n\n  SMARTER\n\n  THAN AN\n\n  ENGINEER?");

}

void Gameplay_Load(void) {
	//get player name from storage

	Gameplay_init();
}

void Gameplay_restartGame(void) {
	//save score in memory

	Gameplay_init();
}

//change player : function to store new name in memory

