/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "uart.h"

/*--- declaracion de funciones ---*/
int Main(void);
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void Eint4567_init();
extern void keyboard_init();
extern void D8Led_init(void);
extern void D8Led_symbol(int value);

char str[1];

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	Uart_Init(115200); // inicializacion de la Uart

	char *pt_str = str;
	while(1){
	}
	return 0;
}
