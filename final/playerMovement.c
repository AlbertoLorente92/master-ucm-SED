#include "playerMovement.h"

extern int map16x16[];
extern int exitPosX;
extern int exitPosY;

extern int foldPlayerPosX;
extern int foldPlayerPosY;
extern int fplayerPosX;
extern int fplayerPosY;

int oldPlayerPosX = -1;
int oldPlayerPosY = -1;
int playerPosX = -1;
int playerPosY = -1;

extern int contSp;

extern int player1;
extern int player2;

void initPlayerPosition16x16(int isMine){
	int pos1X, pos1Y, pos2X, pos2Y;
	int i, j;
	while(1){
		i = rand() % (320/16);
		j = rand() % (240/16);
		if(isValidPos(i, j)){
			pos1X = i;
			pos1Y = j;
			break;
		}
	}
	while(1){
		i = rand() % (320/16);
		j = rand() % (240/16);
		if(isValidPos(i, j) && ((pos1X != i) || (pos1X != j))){
			pos2X = i;
			pos2Y = j;
			break;
		}
	}

	if (isMine){
		playerPosX = pos1X*16;
		playerPosY = pos1Y*16;
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;

		fplayerPosX = pos2X*16;
		fplayerPosY = pos2Y*16;
		foldPlayerPosY = fplayerPosY;
		foldPlayerPosX = fplayerPosX;

		player1 = 0;
		player2 = 1;
	}else{
		playerPosX = pos2X*16;
		playerPosY = pos2Y*16;
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;

		fplayerPosX = pos1X*16;
		fplayerPosY = pos1Y*16;
		foldPlayerPosY = fplayerPosY;
		foldPlayerPosX = fplayerPosX;

		player1 = 1;
		player2 = 0;
	}
}

int isValidPos(int x, int y){
	int freeNeighbors = 0;
	if(map16x16[y*(320/16) + x] != NoNe)
		return 0;
	if (x-1 >= 0)
		if (map16x16[y*(320/16) + x -1] == NoNe){
			freeNeighbors += 1;
		}
	if (x+1 < 320/16)
		if (map16x16[y*(320/16) + x +1] == NoNe){
			freeNeighbors += 1;
		}
	if (y-1 >= 0)
		if (map16x16[(y-1)*(320/16) + x] == NoNe){
			freeNeighbors += 1;
		}
	if (y+1 < 240/16)
		if (map16x16[(y+1)*(320/16) + x] == NoNe){
			freeNeighbors += 1;
		}
	if(freeNeighbors >= 2)
		return 1;
	return 0;
}

void checkWinGame(){
	int playerTopLeftX = playerPosX/16;
	int playerTopLeftY = playerPosY/16;
	int playerBotRigthX = (playerPosX+15)/16;
	int playerBotRigthY = (playerPosY+15)/16;

	if((exitPosX==playerTopLeftX && exitPosY==playerTopLeftY) || (exitPosX==playerBotRigthX && exitPosY==playerBotRigthY)){
		gameWin();
	}

}

int isValidPosition(int x, int y){
	int i, j;
	//Top, Left.
	i = x /16;	j = y /16;
	if(map16x16[j*(320/16) + i] != NoNe)
		return 0;

	//Top, Right.
	i = (x+15) /16;	j = y /16;
	if(map16x16[j*(320/16) + i] != NoNe)
		return 0;

	//Bottom, Left.
	i = x /16;	j = (y+15) /16;
	if(map16x16[j*(320/16) + i] != NoNe)
		return 0;

	//Bottom, Right.
	i = (x+15) /16;	j = (y+15) /16;
	if(map16x16[j*(320/16) + i] != NoNe)
		return 0;

	// Return OK.
	return 1;

}

/* Dado a los obstaculos que rodean al mapa no es necesario preocuparnos de salir del mapa.*/
void movePlayerUp(void){
	if(isValidPosition(playerPosX, playerPosY -1)){
		playerPosY -= 1;
		enviarPosPlayer(playerPosX, playerPosY, contSp);
	}
}

void movePlayerDown(void){
	if(isValidPosition(playerPosX, playerPosY +1)){
		playerPosY += 1;
		enviarPosPlayer(playerPosX, playerPosY, contSp);
	}
}

void movePlayerLeft(void){
	if(isValidPosition(playerPosX -1, playerPosY)){
		playerPosX -= 1;
		enviarPosPlayer(playerPosX, playerPosY, contSp);
	}
}

void movePlayerRight(void){
	if(isValidPosition(playerPosX +1, playerPosY)){
		playerPosX += 1;
		enviarPosPlayer(playerPosX, playerPosY, contSp);
	}
}
