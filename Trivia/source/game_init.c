#include "game_init.h"
#include <stdio.h>

void Gameplay_init(void) {
	int i,j;

	// Rectangle in touchscreen for "Name of player"
	for(i=24;i<31;i++)
		for(j=2;j<5;j++)
			mapMemory_sub[i+(j*32)] = 1;

	// Rectangles in touchscreen for "single" and "multiplayer"
	for(i=2;i<14;i++)
		for(j=7;j<18;j++)
			mapMemory_sub[i+(j*32)] = 1;

	for(i=18;i<30;i++)
		for(j=7;j<18;j++)
			mapMemory_sub[i+(j*32)] = 1;

	// Rectangle for top score
	for(i=10;i<22;i++)
		for(j=20;j<22;j++)
			mapMemory_sub[i+(j*32)] = 1;

	// Name of the game
	for(i=10;i<22;i++)
		for(j=6;j<18;j++)
			mapMemory[i+(j*32)] = 0;
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

