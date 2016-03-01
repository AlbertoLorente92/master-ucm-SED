/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void keyboard_init();
extern void D8Led_init(void);

//Declarar funciones externas de inicialización

/*--- declaracion de funciones ---*/
void Main(void);
/*--- codigo de funciones ---*/
void Main(void)
{
	sys_init();
	timer_init();
	leds_off();
	led1_on();
	while (1); // espera
}
