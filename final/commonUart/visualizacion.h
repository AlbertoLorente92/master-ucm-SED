#ifndef VISUALIZACION_H_
#define VISUALIZACION_H_

#include "lcd.h"
#include <stdlib.h>

#define Wall	(0x2)
#define Dirt	(0x1)
#define NoNe	(0x0)

#define NUMBER_OF_DIRT (0x60) // 96

void init_visualizacion(void);
void drawMap16x16(void);
void drawWall16x16(int x, int y);
void drawDirt16x16(int x, int y);
void generateDirt16x16(void);
void drawPlayer16x16(void);
void clearPlayer16x16(void);
void clear16x16(int posX, int posY);
void drawBomb16x16(int posX, int posY);
void redrawChanging();

#endif /* VISUALIZACION_H_ */
