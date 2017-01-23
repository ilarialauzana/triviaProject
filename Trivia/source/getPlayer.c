#include "getPlayer.h"
#include <stdio.h>
#include <string.h>


char* getPlayer(PrintConsole* pcSub)
{
	Keyboard* kb = keyboardInit(NULL,1,BgType_Text4bpp,BgSize_T_256x256,7,1,false,true);
	char* playerName = "";
	char* c;
	int maxLen = 6;

	BG_PALETTE_SUB[0] = ARGB16(1,12,22,12);

	keyboardShow();

	consoleSelect(pcSub);
	consoleSetWindow(pcSub,3,3,29,7);
	iprintf("Insert your name:\n(max 6 chars)\n\n");

	while(strlen(playerName) < maxLen)
	{
		keyboardGetString(c,1);
		if(strcmp(c,"") == 0)
			break;
		strcat(playerName, c);
		//iprintf("%s",playerName);
		iprintf("%s",c);
	}

	iprintf("\n\nPress any key to save, press start to exit/repeat");

	keyboardGetString(c,1);

	consoleClear();

	return playerName;
}
