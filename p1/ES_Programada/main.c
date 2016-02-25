/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void led1_on();
extern void leds_switch();
extern void Eint4567_init(void);
//extern void sys_init();
/*--- declaracion de funciones ---*/
//void Main(void);
/*--- codigo de funciones ---*/

void Main(void)
{
	/* Inicializar controladores */
	 rPCONG &= ~(1<<6 & 1<<7);
	 rPUPG = 0;
	//sys_init(); // Inicializacion de la placa, interrupciones y puertos
	/* Establecer valor inicial de los LEDs */
	leds_off();
	led1_on();
	while (1){
		if ((rPDATG & (1<<6)) == 0 || (rPDATG & (1<<7)) == 0 ){
			leds_switch();
			DelayMs(100);
			while((rPDATG & (1<<6)) == 0 || (rPDATG & (1<<7)) == 0){}
		}
	}
}
