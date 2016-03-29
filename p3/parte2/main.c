#include "s3cev40.h"
#include "common_types.h"
#include "at24c04.h"
#include "stdio.h"

extern void DelayMs(int ms_time);
extern void sys_init();
extern void iic_init();
extern void D8Led_symbol(int value);
extern void leds_off();
extern void led1_on();
extern void led2_on();
//extern void Eint4567_init(int* _estado, int* _control, int* _dir, int* _dato);
extern void Eint4567_init();
int estado;
int control;
uint16 dir;
uint8 dato;




void Main( void )
{
	estado = 0;
	control = 1;
	dir = 0;
	dato = 0;
    sys_init();
	D8Led_init();

	/*int* estado		= malloc(sizeof(int));
	int* control	= malloc(sizeof(int));
	int* dir 	= malloc(sizeof(int));
	int* dato 	= malloc(sizeof(int));
	*estado = 0;
	*control = 1;
	*dir = 0;
	*dato = 0;*/
	
    Eint4567_init();
    keyboard_init();
    iic_init();

    leds_off();
    led1_on();

	int aux = 0;
    while( 1 ){
    	DelayMs(50);
    	aux = (aux + 1) % 2;
    	if(estado == 0){
    		leds_off();
    	}
    	if(estado == 1){
    		leds_off();
    		led1_on();
    	}
    	if(estado == 2){
    		leds_off();
    		led2_on();
    	}
    	if(estado == 3){
    		led1_on();
    		led2_on();
    	}
    	if(estado == 4){
    		leds_off();
    		if (aux == 1){
    			led1_on();
    		}
    	}
    	if(estado == 5){
    		leds_off();
    		if (aux == 1){
    			led2_on();
    		}
    	}
    }
}
