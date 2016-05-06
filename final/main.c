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



/*--- declaracion de funciones ---*/
int Main(void);

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	Uart_Init(115200); // inicializacion de la Uart
	keyboard_init();
	Eint4567_init();

	init_visualizacion();
	generateDirt16x16();
	initExitPosition16x16();
	drawMap16x16();

	initPlayerPosition16x16();
	//drawPlayer16x16();

	timer_init();

	while(1){
	}
	return 0;
}
