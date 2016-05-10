/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "uart.h"
#include "visualizacion.h"
#include "playerMovement.h"

extern void keyboard_init();
extern void timer_init();
extern void Eint4567_init();
extern void initExitPosition16x16(void);

extern int playPress;
extern int gameSeed;
extern int friendSeed;


/*--- declaracion de funciones ---*/
int Main(void);

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	friendSeed = -1;
	Uart_Init(115200); // inicializacion de la Uart
	keyboard_init();
	Eint4567_init();

	init_visualizacion();
	init_welcomeBoom();

	playPress = 0;
	gameSeed = 0;

	/* Hack un maletin. */
	playPress = 1;
	gameSeed = 1;
	friendSeed = 5;
	/* Hack un maletin. */

	while(playPress == 0){
		gameSeed +=1;
	}

	enviarSeed(gameSeed);
	gameSeed = gameSeed & 0x01F;

	while(friendSeed == -1){}

	int isMine;
	if (gameSeed > friendSeed){
		srand(gameSeed);
		isMine = 1;
	}else{
		srand(friendSeed);
		isMine = 0;
	}

	generateDirt16x16();
	initExitPosition16x16();
	lcd_clear();
	drawMap16x16();

	initPlayerPosition16x16(isMine);

	timer_init();

	while(1){
	}
	return 0;
}
