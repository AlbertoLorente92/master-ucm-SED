#include "bombLogic.h"

int bombPosX = -1;
int bombPosY = -1;

void setBomb(int posX, int posY){
	// Si ya esta plantada la bomba fuera.
	if (bombPosX != -1 || bombPosY != -1)
		return;

	// Ponemos la bomba en al cuadradito en el que mas metidos estemos
	bombPosX = ((posX + 16/2) /16)*16;
	bombPosY = ((posY + 16/2) /16)*16;

	//rTCON |= 0x1<<12;

	redrawChanging();
}

void boomBomb(void){
	if (bombPosX != -1 || bombPosY != -1)
			return;

	clear16x16(bombPosX, bombPosY);
	redrawChanging();

	bombPosX = -1;
	bombPosY = -1;
}
