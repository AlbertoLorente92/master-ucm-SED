/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void led1_on();
extern void keyboard_init(int* timer);
extern void timer_init(int* count, int* dir, int* timer);
extern void Eint4567_init(int* dir);
extern void D8Led_init(void);

/*--- declaracion de funciones ---*/
void Main(void);
/*--- codigo de funciones ---*/
void Main(void)
{
	int* count = malloc(sizeof(int));	*count = 0;
	int* dir = malloc(sizeof(int));		*dir = 1;
	int* timer = malloc(sizeof(int));	*timer = 0;

	sys_init();
	D8Led_init();
	timer_init(count, dir, timer);
	keyboard_init(timer);
	Eint4567_init(dir);
	leds_off();
	led1_on();
	while (1);
}
