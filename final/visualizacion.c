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

extern int oldPlayerPosX;
extern int oldPlayerPosY;
extern int playerPosX;
extern int playerPosY;

extern int bombPosX;
extern int bombPosY;


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
	// TODO
	int i;
	for (i = 0; i<16; i++){
		lcd_putpixel(playerPosX+i, playerPosY+i, BLACK);
	}
}

// TODO eliminar este y utilizar clear16x16.
void clearPlayer16x16(void){ // Que acepte parametros
	int i;
	for (i = 0; i<16; i++){
		lcd_putpixel(playerPosX+i, playerPosY+i, WHITE);
	}
}

void clear16x16(posX, posY){
	int i, j;
		for (i = 0; i<16; i++)
			for (j = 0; j<16; j++)
				lcd_putpixel(posX+i, posY+j, WHITE);
}

void drawBomb16x16(int posX, int posY){
	int i, j;
		for (i = 0; i<16; i++)
			for (j = 0; j<16; j+=2)
				lcd_putpixel(posX+i, posY+j, BLACK);
}

void redrawChanging(){
	//Clear
	clear16x16(oldPlayerPosX, oldPlayerPosY);
	if (bombPosX != -1 || bombPosY != -1)
		clear16x16(bombPosX, bombPosY);

	//Draw
	drawPlayer16x16();
	if (bombPosX != -1 || bombPosY != -1)
		drawBomb16x16(bombPosX, bombPosX);
}
