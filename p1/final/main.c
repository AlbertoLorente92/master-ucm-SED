/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void Eint4567_init(void);
extern void D8Led_init(void);
extern void sys_init();
/*--- declaracion de funciones ---*/
//void Main(void);
/*--- codigo de funciones ---*/

void Main(void)
{
	sys_init();
	leds_off();
	Eint4567_init();
	D8Led_init();
	while (1){}
}
