#include "visualizacion.h"

int map16x16[(320/16) * (240/16)] = {
	Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, NoNe, Wall, Wall,
	Wall, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, NoNe, Wall,
	Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall,
};

/*int playerOne16x16Frontal1[16*16] ={
		0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
		0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
		0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
		0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
		0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b0011,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0011,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b1101,0b0011,0b1011,0b0100,0b0011,0b1101,0b1101,0b0011,0b0100,0b1011,0b0011,0b1101,0b0000,0b0000,
		0b0000,0b1101,0b0011,0b1011,0b1101,0b1011,0b0100,0b0100,0b0100,0b0100,0b1011,0b1101,0b1011,0b0011,0b1101,0b0000,
		0b0000,0b1101,0b0100,0b0100,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0100,0b0100,0b1101,0b0000,
		0b0000,0b0000,0b1101,0b1101,0b1101,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1101,0b1101,0b1101,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b0101,0b1101,0b1101,0b0101,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1110,0b1110,0b1101,0b1101,0b1110,0b1110,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000
};

int playerOne16x16Frontal2[16*16] ={
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
		0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
		0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
		0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
		0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b0011,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b1101,0b0011,0b1011,0b0100,0b0011,0b1101,0b1101,0b0011,0b1101,0b0011,0b0011,0b1101,0b0000,0b0000,
		0b0000,0b1101,0b0011,0b1011,0b1101,0b1011,0b0011,0b0011,0b0011,0b1011,0b1101,0b0011,0b0100,0b1101,0b0000,0b0000,
		0b0000,0b1101,0b0100,0b0011,0b1101,0b1011,0b1011,0b1011,0b1011,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1100,0b1100,0b1101,0b1101,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1110,0b1110,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000
};

int playerOne16x16Frontal3[16*16] ={
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
		0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
		0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
		0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
		0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0011,0b1101,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b1101,0b0011,0b0011,0b1101,0b0011,0b1101,0b1101,0b0011,0b0100,0b1011,0b0011,0b1101,0b0000,0b0000,
		0b0000,0b0000,0b1101,0b0100,0b0011,0b1101,0b0100,0b0100,0b0100,0b0100,0b1011,0b1101,0b1011,0b0011,0b1101,0b0000,
		0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1011,0b1011,0b1011,0b1011,0b1101,0b0100,0b0100,0b1101,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1101,0b1101,0b1100,0b1100,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1110,0b1110,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000
};*/

extern int oldPlayerPosX;
extern int oldPlayerPosY;
extern int playerPosX;
extern int playerPosY;

int foldPlayerPosX = 0;
int foldPlayerPosY = 0;
int fplayerPosX = 0;
int fplayerPosY = 0;
int fpSprite = 0;

extern int bombPosX;
extern int bombPosY;

extern int fbombPosX;
extern int fbombPosY;

int contSp = 0;
uint8 spFrontal[3][16*16] = {
		{
				0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
				0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
				0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
				0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
				0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b0011,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0011,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b1101,0b0011,0b1011,0b0100,0b0011,0b1101,0b1101,0b0011,0b0100,0b1011,0b0011,0b1101,0b0000,0b0000,
				0b0000,0b1101,0b0011,0b1011,0b1101,0b1011,0b0100,0b0100,0b0100,0b0100,0b1011,0b1101,0b1011,0b0011,0b1101,0b0000,
				0b0000,0b1101,0b0100,0b0100,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0100,0b0100,0b1101,0b0000,
				0b0000,0b0000,0b1101,0b1101,0b1101,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1101,0b1101,0b1101,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b0101,0b1101,0b1101,0b0101,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1110,0b1110,0b1101,0b1101,0b1110,0b1110,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000
		},
		{
				0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
				0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
				0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
				0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
				0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
				0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b0011,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b1101,0b0011,0b1011,0b0100,0b0011,0b1101,0b1101,0b0011,0b1101,0b0011,0b0011,0b1101,0b0000,0b0000,
				0b0000,0b1101,0b0011,0b1011,0b1101,0b1011,0b0011,0b0011,0b0011,0b1011,0b1101,0b0011,0b0100,0b1101,0b0000,0b0000,
				0b0000,0b1101,0b0100,0b0011,0b1101,0b1011,0b1011,0b1011,0b1011,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1100,0b1100,0b1101,0b1101,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1110,0b1110,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000
		},
		{
				0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
				0b1110,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1110,
				0b1110,0b1110,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,0b0000,0b1110,0b1110,
				0b1110,0b1110,0b1110,0b1110,0b1101,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b1101,0b1110,0b1110,0b1110,0b1110,
				0b0000,0b1110,0b1110,0b1111,0b0011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b0011,0b1111,0b1110,0b1110,0b0000,
				0b0000,0b0000,0b1111,0b1111,0b0011,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0011,0b1111,0b1111,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b0100,0b0001,0b1110,0b0001,0b0001,0b1110,0b0001,0b0100,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b1011,0b0010,0b0001,0b0010,0b0010,0b0001,0b0010,0b1011,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1101,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b1101,0b0011,0b1101,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b1101,0b0011,0b0011,0b1101,0b0011,0b1101,0b1101,0b0011,0b0100,0b1011,0b0011,0b1101,0b0000,0b0000,
				0b0000,0b0000,0b1101,0b0100,0b0011,0b1101,0b0100,0b0100,0b0100,0b0100,0b1011,0b1101,0b1011,0b0011,0b1101,0b0000,
				0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1011,0b1011,0b1011,0b1011,0b1101,0b0100,0b0100,0b1101,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1101,0b1101,0b1100,0b1100,0b1101,0b1101,0b1101,0b1101,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b1101,0b1101,0b1101,0b1101,0b1110,0b1110,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000,
				0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1101,0b1111,0b1111,0b1101,0b0000,0b0000,0b0000,0b0000,0b0000
		}
};

int bombSprite16x16[16*16] ={
		0b0000,0b0000,0b0010,0b0100,0b1111,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0010,0b0001,0b0010,0b0000,0b0000,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0010,0b0000,0b0000,0b0000,0b0000,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1111,0b1111,0b1111,0b1111,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1111,0b1110,0b1100,0b0100,0b0101,0b0101,0b1111,0b1110,0b1111,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1111,0b1110,0b0011,0b0100,0b0011,0b0100,0b0101,0b0110,0b1111,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1110,0b0011,0b0100,0b0011,0b0100,0b0011,0b0100,0b0100,0b1111,0b1100,0b1110,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1100,0b0100,0b0011,0b0011,0b0011,0b0100,0b0100,0b0101,0b1111,0b1100,0b1101,0b1111,0b0000,
		0b0000,0b0000,0b1111,0b1100,0b0011,0b0100,0b0011,0b0100,0b0011,0b0100,0b0100,0b1111,0b1100,0b1101,0b1111,0b0000,
		0b0000,0b0000,0b1111,0b1100,0b0100,0b0011,0b0100,0b0011,0b0100,0b0101,0b0110,0b1111,0b1100,0b1110,0b1111,0b0000,
		0b0000,0b0000,0b1111,0b1100,0b0101,0b0100,0b0100,0b0100,0b0101,0b0101,0b1111,0b1111,0b1100,0b1110,0b1111,0b0000,
		0b0000,0b0000,0b1111,0b1100,0b1111,0b0101,0b0101,0b0100,0b0110,0b1111,0b1111,0b1100,0b1101,0b1110,0b1111,0b0000,
		0b0000,0b0000,0b0000,0b1110,0b1100,0b1111,0b1111,0b1111,0b1111,0b1111,0b1100,0b1101,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1111,0b1110,0b1100,0b1100,0b1100,0b1100,0b1101,0b1101,0b1110,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1111,0b1110,0b1101,0b1101,0b1110,0b1110,0b1110,0b1111,0b1111,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b1111,0b1111,0b1111,0b1111,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000
};

int exitSprite16x16[16*16] ={
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b1111,0b1111,0b1111,0b1111,0b1111,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1111,0b1110,0b1110,0b1110,0b1110,0b1110,0b1110,0b1111,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1111,0b1110,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1110,0b1111,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1110,0b1100,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1100,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1110,0b1100,0b1011,0b0100,0b0100,0b0100,0b0100,0b1011,0b1100,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1110,0b1100,0b1011,0b0100,0b0000,0b0000,0b0100,0b1011,0b1100,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1110,0b1100,0b1011,0b0100,0b0100,0b0100,0b0100,0b1011,0b1100,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b1111,0b1110,0b1100,0b1011,0b1011,0b1011,0b1011,0b1011,0b1011,0b1100,0b1110,0b1111,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b1111,0b1110,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1110,0b1111,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b1111,0b1110,0b1110,0b1110,0b1110,0b1110,0b1110,0b1111,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b1111,0b1111,0b1111,0b1111,0b1111,0b1111,0b0000,0b0000,0b0000,0b0000,0b0000,
		0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000
};

int getSprite(int cont){
	int x;

	switch(cont){
		case 0:
			x = 0;
		break;

		case 1:
			x = 1;
		break;

		case 2:
			x = 0;
		break;

		case 3:
			x = 2;
		break;

		default:
			x = 0;
		break;
	}

	return x;
}

void init_visualizacion(void){
	lcd_init();
	lcd_clear();
}

void drawMap16x16(void){
	int i, j;
	for (i = 0; i<320/16; i++)
		for (j = 0; j<240/16; j++){
			if(map16x16[j*(320/16) + i] == Wall)
				drawWall16x16(i, j);
			if(map16x16[j*(320/16) + i] == Dirt)
				drawDirt16x16(i, j);
		}
}

void drawWall16x16(int x, int y){
	x *=16;
	y *=16;

	int i, j;
	for (i = x; i<x+16; i++)
		for (j = y; j<y+16; j++)
			lcd_putpixel(i, j, BLACK);
}

void drawDirt16x16(int x, int y){
	x *=16;
	y *=16;

	int i, j;
	for (i = x; i<x+16; i++)
		for (j = y; j<y+16; j++){
			if(((i%2)==0) || ((j%2)==0))
				lcd_putpixel(i, j, LIGHTGRAY);
			else
				lcd_putpixel(i, j, DARKGRAY);
		}
}

void drawExit16x16(int x,int y){
	int i, j;
	for (i = 0; i<16; i++){
		for (j = 0; j<16; j++){
			lcd_putpixel(x+i, y+j, exitSprite16x16[(j*16)+i]);
		}
	}
}

void generateDirt16x16(void){
	int aux = 0;
	int i, j;
	while(aux < NUMBER_OF_DIRT){
		i = rand() % (320/16);
		j = rand() % (240/16);
		if(map16x16[j*(320/16) + i] == NoNe){
			map16x16[j*(320/16) + i] = Dirt;
			aux++;}
	}
}

// TODO Que acepte parametros, como drawBimb16x16
void drawPlayer16x16(void){
	int i,j;
	for (i = 0; i<16; i++){
		for (j = 0; j<16; j++){
			int aux = getSprite(contSp);
			if(spFrontal[aux][(j*16)+i] != 0b0000){
				lcd_putpixel(playerPosX+i, playerPosY+j, spFrontal[aux][(j*16)+i] );
			}
		}
	}
	contSp = (contSp +1)%4;
}

void drawPlayerF16x16(int posX, int posY, int aux){
	int i,j;
	for (i = 0; i<16; i++){
		for (j = 0; j<16; j++){
			if(spFrontal[aux][(j*16)+i] != 0b0000){
				lcd_putpixel(posX+i, posY+j, spFrontal[aux][(j*16)+i] );
			}
		}
	}
}

// TODO eliminar este y utilizar clear16x16.
void clearPlayer16x16(void){ // Que acepte parametros
	int i;
	for (i = 0; i<16; i++){
		lcd_putpixel(playerPosX+i, playerPosY+i, WHITE);
	}
}

void clear16x16(int posX, int posY){
	lcd_clear16x16(posX, posY);
}

void drawBomb16x16(int posX, int posY){
	int i, j;
	for (i = 0; i<16; i++){
		for (j = 0; j<16; j++)	{
			if(bombSprite16x16[(j*16)+i] != 0b0000){
				lcd_putpixel(posX+i, posY+j, bombSprite16x16[(j*16)+i]);
			}
		}
	}
}

void redrawChanging(){
	//Clear
	clear16x16(oldPlayerPosX, oldPlayerPosY);
	clear16x16(foldPlayerPosX, foldPlayerPosY);
	if (bombPosX != -1 || bombPosY != -1)
		clear16x16(bombPosX, bombPosY);
	if (fbombPosX != -1 || fbombPosY != -1)
			clear16x16(fbombPosX, fbombPosY);

	//Draw
	if (bombPosX != -1 || bombPosY != -1)
		drawBomb16x16(bombPosX, bombPosY);
	if (fbombPosX != -1 || fbombPosY != -1)
		drawBomb16x16(fbombPosX, fbombPosY);
	drawPlayerF16x16(fplayerPosX, fplayerPosY, fpSprite);
	foldPlayerPosX = fplayerPosX;
	foldPlayerPosY = fplayerPosY;
	drawPlayer16x16();
	oldPlayerPosX = playerPosX;
	oldPlayerPosY = playerPosY;
}
