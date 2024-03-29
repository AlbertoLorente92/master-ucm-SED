/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "def.h"
/*--- variables globales ---*/
int symbol = 0;
/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init(void);
extern void leds_switch ();

/*--- codigo de funciones ---*/
void Eint4567_init(void)
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
}

/*COMENTAR PARA LA PARTE DEL 8-SEGMENTOS
DESCOMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
*/
void Eint4567_ISR(void)
{
	/*Evitamos los rebotes de los pulsadores con la e/s programada comprobando tras
	 * 10ms si la se�al esta activada*/
	DelayMs(10);
	if (!((rPDATG & (1<<6)) == 0 || (rPDATG & (1<<7)) == 0 )){
		//borrar flag de la int.
		rEXTINTPND = 1<<2 | 1<<3;
		rI_ISPC = 1<<21;
		return;
	}

	/**/
	//Conmutamos LEDs
	leds_switch();
	//Delay para eliminar rebotes
	DelayMs(100);
	
	/*Atendemos interrupciones*/
	//Borramos EXTINTPND ambas l�neas EINT7 y EINT6
	rEXTINTPND = 1<<2 | 1<<3;
	//Borramos INTPND usando ISPC
	rI_ISPC = 1<<21;
}

/*
DESCOMENTAR PARA LA PARTE DEL 8-SEGMENTOS
COMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
int which_int;
void Eint4567_ISR(void)
{
	//Identificar la interrupcion
	//which_int = rEXTINTPND;
	//Actualizar simbolo*/
	//switch (which_int) {
	//
	//}
	// muestra el simbolo en el display
	// espera 100ms para evitar rebotes
	
	// borra los bits en EXTINTPND  
	// borra el bit pendiente en INTPND
/*}
*/
