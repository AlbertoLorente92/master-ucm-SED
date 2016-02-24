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
extern void D8Led_symbol(int value);

/*--- codigo de funciones ---*/
void Eint4567_init(void)
{
/* Configuracion del controlador de interrupciones */
	// Borra EXTINTPND escribiendo 1s en el propio registro
	// Borra INTPND escribiendo 1s en I_ISPC
	// Configura las lineas como de tipo IRQ mediante INTMOD
	// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON
	// Enmascara todas las lineas excepto Eint4567 y el bit global (INTMSK)
	// Establecer la rutina de servicio para Eint4567
/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0)
	//Habilita las resistencias de pull-up
	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
}

/*COMENTAR PARA LA PARTE DEL 8-SEGMENTOS
DESCOMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
*/
void Eint4567_ISR(void)
{
	//Conmutamos LEDs
	//Delay para eliminar rebotes
	
	/*Atendemos interrupciones*/
	//Borramos EXTINTPND ambas líneas EINT7 y EINT6
	//Borramos INTPND usando ISPC
}

/*
DESCOMENTAR PARA LA PARTE DEL 8-SEGMENTOS
COMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
int which_int;
void Eint4567_ISR(void)
{
	/*Identificar la interrupcion*/
	//which_int = rEXTINTPND;
	/* Actualizar simbolo*/
	//switch (which_int) {
	//
	//}
	// muestra el simbolo en el display
	// espera 100ms para evitar rebotes
	
	// borra los bits en EXTINTPND  
	// borra el bit pendiente en INTPND
/*}
*/