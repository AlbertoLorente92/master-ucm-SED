/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void led1_on();
extern void leds_switch();
extern void sys_init();
/*--- declaracion de funciones ---*/
//void Main(void);
/*--- codigo de funciones ---*/

void Main(void)
{
	/* Inicializar controladores */
	sys_init();
	rPCONG &= ~(1<<12 & 1<<13 & 1<<14 & 1<<15);
	rPUPG = 0;
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
