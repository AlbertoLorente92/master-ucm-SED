/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void led1_on();
extern void Eint4567_init(void);
extern void sys_init();
/*--- declaracion de funciones ---*/
//void Main(void);
/*--- codigo de funciones ---*/

void Main(void)
{
	/* Inicializar controladores */
	sys_init();
	/* Establecer valor inicial de los LEDs */
	leds_off();
	led1_on();
	Eint4567_init();
	while (1){}
}
