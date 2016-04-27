/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "uart.h"
#include "visualizacion.h"
#include "playerMovement.h"

extern void keyboard_init();


/*--- declaracion de funciones ---*/
int Main(void);

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	//Uart_Init(115200); // inicializacion de la Uart
	keyboard_init();

	init_visualizacion();
	generateDirt16x16();
	drawMap16x16();

	initPlayerPosition16x16();
	drawPlayer16x16();

	while(1){
	}
	return 0;
}
