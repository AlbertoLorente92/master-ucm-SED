/*--- ficheros de cabecera ---*/
#include "common_types.h"
#include "44b.h"
#include "def.h"
#include "at24c04.h"
/*--- variables globales ---*/

/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init(int* _estado, int* _control, uint16* _dir, uint8* _dato);
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void D8Led_symbol(int value);
/*--- Variables globales ---*/

int* estado;
int* control;
uint16* dir;
uint8* dato;
uint16 lastDir = 0;

/*--- codigo de funciones ---*/
void Eint4567_init(int* _estado, int* _control, uint16* _dir, uint8* _dato)
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

	estado 	= _estado;
	control	= _control;
	dir 	= _dir;
	dato 	= _dato;
}

int which_int;
void Eint4567_ISR(void)
{
	led1_on();
	which_int = rEXTINTPND & (1<<2 | 1<<3);
	//uint8 lectura;
	//Actualizar simbolo
	switch (which_int) {
		case 1<<2:
			if (*control == 0){
				break;
			}
			*control = 0;
			*estado = (*estado + 1) % 6;

			if (*estado == 3){
				lastDir = *dir;
			}
			if (*estado == 5){
				at24c04_bytewrite( *dir, *dato );
				*control = 1;
			}
			if(*estado == 0){
				*control = 1;
			}
			break;
		case 1<<3:

			//at24c04_byteread(lastDir, &lectura);
			//int val = lectura & 0xF;
			D8Led_symbol(4);
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
