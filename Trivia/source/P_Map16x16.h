
#include <nds.h>
#include "P_Graphics.h"

u16* mapMemory;
u16* mapMemory_sub;
int MapCols;
int MapRows;


void P_Map16x16_configureBG2_Sub();


void P_Map16x16_configureBG1();
void P_Map16x16_configureBG3();

void P_Map16x16_Init( int cols, int rows );
void SetMap16x16To(int index16, bool full);
