/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "uart.h"
#include "visualizacion.h"

/*--- declaracion de funciones ---*/
int Main(void);

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	Uart_Init(115200); // inicializacion de la Uart

	init_visualizacion();

	while(1){
	}
	return 0;
}
