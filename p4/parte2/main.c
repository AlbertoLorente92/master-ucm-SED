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
	keyboard_init();
	D8Led_init();
	D8Led_symbol(4);
	Eint4567_init();

	char *pt_str = str;
	while(1){
		*pt_str = Uart_Getch(); // leer caracter
		if (*pt_str == 'a'){
			leds_off();
			led1_on();
		}
		if (*pt_str == 'b'){
			leds_off();
			led2_on();
		}
		if (((*pt_str-'0') >= 0) && ((*pt_str-'0') < 16)){
			D8Led_symbol(*pt_str-'0');
		}
		pt_str = str;
	}
	return 0;
}
