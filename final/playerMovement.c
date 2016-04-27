#include "playerMovement.h"

extern int map16x16[];

int playerPosX = -1;
int playerPosY = -1;

void initPlayerPosition16x16(void){
	int i, j;
	while(1){
		i = rand() % (320/16);
		j = rand() % (240/16);
		if(map16x16[j*(320/16) + i] == NoNe){
			playerPosX = i*16;
			playerPosY = j*16;
			break;
		}
	}
}

int isValidPosition(int x, int y){
	int i, j;
	//Top, Left.
	i = x /16;	j = y / (240/16);
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
		clearPlayer16x16();
		playerPosY -= 1;
		drawPlayer16x16();
	}
}

void movePlayerDown(void){
	if(isValidPosition(playerPosX, playerPosY +1)){
		clearPlayer16x16();
		playerPosY += 1;
		drawPlayer16x16();
	}
}

void movePlayerLeft(void){
	if(isValidPosition(playerPosX -1, playerPosY)){
		clearPlayer16x16();
		playerPosX -= 1;
		drawPlayer16x16();
	}
}

void movePlayerRight(void){
	if(isValidPosition(playerPosX +1, playerPosY)){
		clearPlayer16x16();
		playerPosX += 1;
		drawPlayer16x16();
	}
}
