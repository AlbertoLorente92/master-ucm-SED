#include "bombLogic.h"

int bombPosX = -1;
int bombPosY = -1;

extern int map16x16[];
extern int playerPosX;
extern int playerPosY;
extern int exitPosX;
extern int exitPosY;

void setBomb(int posX, int posY){
	// Si ya esta plantada la bomba fuera.
	if (bombPosX != -1 || bombPosY != -1)
		return;

	// Ponemos la bomba en al cuadradito en el que mas metidos estemos
	bombPosX = ((posX + 16/2) /16)*16;
	bombPosY = ((posY + 16/2) /16)*16;

	rTCON |= (0x1<<13);
	rTCON &= ~(0x1<<13);
	rTCON |= (0x1<<15);
	rTCON |= 0x1<<12;

	redrawChanging();
}

void boomBomb(void) {

	if (bombPosX == -1 && bombPosY == -1)
			return;
	clear16x16(bombPosX, bombPosY);

	int playerTopLeftX = playerPosX/16;
	int playerTopLeftY = playerPosY/16;
	int playerBotRigthX = (playerPosX+15)/16;
	int playerBotRigthY = (playerPosY+15)/16;

	int i = bombPosX /16;
	int j = bombPosY /16;


	if((i==playerTopLeftX && j==playerTopLeftY) || (i==playerBotRigthX && j==playerBotRigthY)){
		gameOver();
		return;
	}

	//up.
	j = j-1;
	if(map16x16[j*(320/16) + i] == Dirt){
		clear16x16(i*16,j*16);
		map16x16[j*(320/16) + i] = NoNe;

		if(i==exitPosX && j==exitPosY){
			drawExit16x16(i*16,j*16);
		}
	}

	if((i==playerTopLeftX && j==playerTopLeftY) || (i==playerBotRigthX && j==playerBotRigthY)){
		gameOver();
		return;
	}

	//down.
	j = j+2;
	if(map16x16[j*(320/16) + i] == Dirt){
		clear16x16(i*16,j*16);
		map16x16[j*(320/16) + i] = NoNe;

		if(i==exitPosX && j==exitPosY){
			drawExit16x16(i*16,j*16);
		}
	}

	if((i==playerTopLeftX && j==playerTopLeftY) || (i==playerBotRigthX && j==playerBotRigthY)){
		gameOver();
		return;
	}

	//left
	j--;
	i--;
	if(map16x16[j*(320/16) + i] == Dirt){
		clear16x16(i*16,j*16);
		map16x16[j*(320/16) + i] = NoNe;

		if(i==exitPosX && j==exitPosY){
			drawExit16x16(i*16,j*16);
		}
	}

	if((i==playerTopLeftX && j==playerTopLeftY) || (i==playerBotRigthX && j==playerBotRigthY)){
		gameOver();
		return;
	}

	//right
	i = i+2;
	if(map16x16[j*(320/16) + i] == Dirt){
		clear16x16(i*16,j*16);
		map16x16[j*(320/16) + i] = NoNe;

		if(i==exitPosX && j==exitPosY){
			drawExit16x16(i*16,j*16);
		}
	}

	if((i==playerTopLeftX && j==playerTopLeftY) || (i==playerBotRigthX && j==playerBotRigthY)){
		gameOver();
		return;
	}

	bombPosX = -1;
	bombPosY = -1;
	redrawChanging();
}
