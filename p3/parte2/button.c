/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "def.h"
/*--- variables globales ---*/
int state = 0;
uint8 lastDir = 0;
uint8 lastDato = 0;
/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init(void);
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void D8Led_symbol(int value);
#define KEY_VALUE_MASK 0xF
/*--- Variables globales ---*/
volatile UCHAR *keyboard_base = (UCHAR *)0x06000000;

uint* frag = 0;
uint* dir1MasSig = 0;
uint* dir2MenSig = 0;

uint* dato1MasSig = 0;
uint* dato2MenSig = 0;

/*--- codigo de funciones ---*/
void Eint4567_init(uint* timer,uint* dir1,uint* dir2,uint* dato1,uint* dato2)
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
	rINTMSK |= (~(unsigned int)0)>>5; // Enmascarar todas las lineas, bits [0..26].
	rINTMSK &= ~((1<<21) | (1<<26)); // Habiltar las lineas 21(Eint4567) y 26(bit global)
	// Establecer la rutina de servicio para Eint4567
	pISR_EINT4567 = (unsigned) Eint4567_ISR;
/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0)
	rPCONG &= ~(1<<12 & 1<<13 & 1<<14 & 1<<15);
	//Habilita las resistencias de pull-up
	rPUPG = 0;
	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT &= ~(1<<30 | 1<<26);
	rEXTINT |= 1<<29 | 1<<25;
/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	rEXTINTPND = ~0x0;
	rI_ISPC = ~0x0;
	state = 0;
	frag = timer;
	dir1MasSig = dir1;
	dir2MenSig = dir2;
	dato1MasSig = dato1;
	dato2MenSig = dato2;	
	lastDir = 0;
	lastDato = 0;
}

int which_int;
void Eint4567_ISR(void)
{
	/*Evitamos los rebotes de los pulsadores con la e/s programada comprobando tras
	 * 10ms si la señal esta activada*/
	DelayMs(10);
	if (!((rPDATG & (1<<6)) == 0 || (rPDATG & (1<<7)) == 0 )){
		//borrar flag de la int.
		rEXTINTPND = 1<<2 | 1<<3;
		rI_ISPC = 1<<21;
		return;
	}

	/*Identificar la interrupcion*/
	which_int = rEXTINTPND & (1<<2 | 1<<3);
	/* Actualizar simbolo*/
	switch (which_int) {
		case 1<<2:			
			switch(state){
				case 0:	
				break;
				
				case 1:
					//Espera activa al teclado matricial
					while(	(*(keyboard_base + 0xfd) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xfb) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xf7) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xef) & KEY_VALUE_MASK) == -1){}
					*dir1MasSig = frag;			//igualar contenido no apuntar a frag
				break;
				
				case 2:
					//Espera activa al teclado matricial
					while(	(*(keyboard_base + 0xfd) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xfb) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xf7) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xef) & KEY_VALUE_MASK) == -1){}
					*dir2MenSig = frag;			//igualar contenido no apuntar a frag
				break;
				
				case 3:
					//Espera activa al teclado matricial
					while(	(*(keyboard_base + 0xfd) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xfb) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xf7) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xef) & KEY_VALUE_MASK) == -1){}
					*dato1MasSig = frag;			//igualar contenido no apuntar a frag
				break;
				
				case 4:
					//Espera activa al teclado matricial
					while(	(*(keyboard_base + 0xfd) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xfb) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xf7) & KEY_VALUE_MASK) == -1 &&
							(*(keyboard_base + 0xef) & KEY_VALUE_MASK) == -1){}
					*dato2MenSig = frag;			//igualar contenido no apuntar a frag
				break;
				
				case 5:
					//Escribir en el teclado
					uint dir1 = int_to_int(dir1MasSig);
					uint dir2 = int_to_int(dir2MenSig);
					uint dat1 = int_to_int(dato1MasSig);
					uint dat2 = int_to_int(dato2MenSig);
					uint8 dir = dir1<<4 & dir2;
					uint8 dato = dat1<<4 & dat2;
					lastDir = dir;
					lastDato = dato;
					at24c04_bytewrite( dir, dato );
				break;
			}
			state = (state+1) % 6;
			break;
		case 1<<3:
			uint8 lectura;
			at24c04_byteread(lastDir,lectura);
			state = 0;
			int val = lectura & 0xF;
			D8Led_symbol(val);
			DelayMs(100);
			break;
		default:
			break;
	}
	// muestra el simbolo en el display
	//----symbol &= ((unsigned int)(~0x0))>>(32-4);
	//----D8Led_symbol(symbol);
	// espera 100ms para evitar rebotes
	DelayMs(100);
	
	// borra los bits en EXTINTPND  
	rEXTINTPND = 1<<2 | 1<<3;
	// borra el bit pendiente en INTPND
	rI_ISPC = 1<<21;
}

unsigned int_to_int(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;                       /* optional */
    return (k % 2) + 10 * int_to_int(k / 2);
}
