#include "s3cev40.h"
#include "common_types.h"
#include "at24c04.h"

extern void DelayMs(int ms_time);
extern void sys_init();
extern void iic_init();
extern void D8Led_symbol(int value);
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void Eint4567_init(int* _estado, int* _control, uint16* _dir, uint8* _dato);


void Main( void )
{
	int* estado		= malloc(sizeof(int));		*estado = 0;
	int* control	= malloc(sizeof(int));		*control = 1;
	uint16* dir 	= malloc(sizeof(uint16));	*dir = 0;
	uint8* dato 	= malloc(sizeof(uint8));	*dato = 0;
	
    sys_init();
	D8Led_init();
    //Eint4567_init(estado, control, dir, dato);
    //keyboard_init(estado, control, dir, dato);
    //iic_init();
    D8Led_symbol(7);

    leds_off();
    led1_on();
    *estado = 1;
	int aux = 0;
    while( 1 ){
    	DelayMs(50);
    	aux = (aux + 1) % 2;
    	if(*estado == 0){
    		leds_off();
    	}
    	if(*estado == 1){
    		leds_off();
    		led1_on();
    	}
    	if(*estado == 2){
    		leds_off();
    		led2_on();
    	}
    	if(*estado == 3){
    		led1_on();
    		led2_on();
    	}
    	if(*estado == 4){
    		leds_off();
    		if (aux == 1){
    			led1_on();
    		}
    	}
    	if(*estado == 5){
    		leds_off();
    		if (aux == 1){
    			led2_on();
    		}
    	}
    }
}
