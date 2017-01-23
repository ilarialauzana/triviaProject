#include <nds.h>
#include "P_Controls.h"
#include "game_init.h"
#include "P_Initializer.h"

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	
    P_InitNDS();

    //srand( clock() );
	Gameplay_Load();
	while( true ) {
		keyboardUpdate();
		//handleInput();
		swiWaitForVBlank();
	}

	return 0;
}
