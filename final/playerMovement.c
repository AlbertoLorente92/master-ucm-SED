#include "playerMovement.h"

extern int map16x16[];


int oldPlayerPosX = -1;
int oldPlayerPosY = -1;
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
			oldPlayerPosY = playerPosY;
			oldPlayerPosX = playerPosX;
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
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
		playerPosY -= 1;
		redrawChanging();
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
	}
}

void movePlayerDown(void){
	if(isValidPosition(playerPosX, playerPosY +1)){
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
		playerPosY += 1;
		redrawChanging();
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
	}
}

void movePlayerLeft(void){
	if(isValidPosition(playerPosX -1, playerPosY)){
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
		playerPosX -= 1;
		redrawChanging();
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
	}
}

void movePlayerRight(void){
	if(isValidPosition(playerPosX +1, playerPosY)){
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
		playerPosX += 1;
		redrawChanging();
		oldPlayerPosY = playerPosY;
		oldPlayerPosX = playerPosX;
	}
}
