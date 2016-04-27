#include "bombLogic.h"

int bombPosX = -1;
int bombPosY = -1;

void setBomb(int posX, int posY){
	// Si ya esta plantada la bomba fuera.
	if (bombPosX != -1 || bombPosY != -1)
		return;

	// Ponemos la bomba en al cuadradito en el que mas metidos estemos
	bombPosX = ((posX + 16/2) / 320/16);
	bombPosY = ((posX + 16/2) / 240/16);

	redrawChanging();
}
