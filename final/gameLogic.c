#include "gameLogic.h"

int playPress;
int gameSeed;
int friendSeed;

int exitPosX;
int exitPosY;

extern int map16x16[];

void initExitPosition16x16(void){
	int i, j;
	while(1){
		i = rand() % (320/16);
		j = rand() % (240/16);
		if(map16x16[j*(320/16) + i] == Dirt){
			exitPosX = i*16;
			exitPosY = j*16;
			break;
		}
	}
	//TODO remove this shit
	exitPosX=10;
	exitPosY=5;
}

void _gameOver(void){
	// deshabilitar timer
	rINTMSK |= (1<<13 | 1<<12 | 1<<11);
	// deshabilitar button
	rINTMSK |= (1<<21);

	drawWin();
}

void gameOver(void){
	enviarGameLose();
	_gameOver();
}

void _gameWin(void){
	// deshabilitar timer
	rINTMSK |= (1<<13 | 1<<12 | 1<<11);
	// deshabilitar button
	rINTMSK |= (1<<21);

	drawLose();
}

void gameWin(void){
	enviarGameWin();
	_gameWin();
}
