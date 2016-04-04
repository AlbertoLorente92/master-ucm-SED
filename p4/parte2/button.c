/*--- ficheros de cabecera ---*/
#include "common_types.h"
#include "44b.h"
#include "def.h"
#include "at24c04.h"
#include "uart.h"
/*--- variables globales ---*/

/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init();
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void D8Led_symbol(int value);
/*--- Variables globales ---*/

extern int estado;
extern int control;
extern uint16 dir;
extern uint8 dato;
uint16 lastDir = 0;

/*--- codigo de funciones ---*/
void Eint4567_init()
{
/* Configuracion del controlador de interrupciones */
	// Borra EXTINTPND escribiendo 1s en el propio registro
	rEXTINTPND = ~0x0;
	// Borra INTPND escribiendo 1s en I_ISPC
	rI_ISPC = ~0x0;
	// Configura las lineas como de tipo IRQ mediante INTMOD
	rINTMOD = 0x0;
	// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON
	rINTCON &= ~(0x1<<1 | 0x1<<2);
	rINTCON |= 0x1<<0;
	// Enmascara todas las lineas excepto Eint4567 y el bit global (INTMSK)
	rINTMSK &= ~((1<<21) | (1<<26)); // Habiltar las lineas 21(Eint4567) y 26(bit global)
	// Establecer la rutina de servicio para Eint4567
	pISR_EINT4567 = (unsigned) Eint4567_ISR;
/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0)
	rPCONG |= (1<<12 | 1<<13 | 1<<14 | 1<<15);
	//Habilita las resistencias de pull-up
	rPUPG = 0;
	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT &= ~(1<<30 | 1<<26);
	rEXTINT |= 1<<29 | 1<<25;
/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	rEXTINTPND = ~0x0;
	rI_ISPC = ~0x0;
}

int which_int;
void Eint4567_ISR(void)
{
	which_int = rEXTINTPND & (1<<2 | 1<<3);
	char left[1] = "a";
	char right[1] = "b";
	switch (which_int) {
		case 1<<2:
			Uart_SendByte(left);
			break;
		case 1<<3:
			Uart_SendByte(pt_str);
			break;
		default:
			break;
	}

	DelayMs(100);
	// borra los bits en EXTINTPND  
	rEXTINTPND = 1<<2 | 1<<3;
	// borra el bit pendiente en INTPND
	rI_ISPC = 1<<21;
}
