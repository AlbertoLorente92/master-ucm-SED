/*--- Ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
#include "def.h"
/*--- Definición de macros ---*/
#define KEY_VALUE_MASK 0xF
/*--- Variables globales ---*/
volatile UCHAR *keyboard_base = (UCHAR *)0x06000000;
int key;
/*--- Declaracion de funciones ---*/
void keyboard_init();
void KeyboardInt(void) __attribute__ ((interrupt ("IRQ")));
void key_read();
int* _timer;

/*--- Codigo de las funciones ---*/
void keyboard_init(int* timer)
{
	/* Configurar el puerto G (si no lo estuviese ya) */	
		// Establece la funcion de los pines (EINT0-7)
	rPCONG &= ~(1<<2 & 1<<3);
		// Habilita el "pull up" del puerto
	rPUPG = 0;
		// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT &= ~(1<<6);
	rEXTINT |= 1<<5;
	/* Establece la rutina de servicio para EINT1 */
	pISR_EINT1 = (unsigned) KeyboardInt;
		//
	/* Configurar controlador de interrupciones */
		// Borra INTPND escribiendo 1s en I_ISPC
	rI_ISPC = ~0x0;
		// Configura las lineas como de tipo IRQ mediante INTMOD
	rINTMOD = 0x0;
		// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON
	rINTCON &= ~(0x1<<1 | 0x1<<2);
	rINTCON |= 0x1<<0;
	/* Habilitar linea EINT1 */
	rINTMSK &= ~((1<<24) | (1<<26)); // Habiltar las lineas 24(Eint1) y 26(bit global)
	/* Por precaucion, se vuelven a borrar los bits de INTPND correspondientes*/
	rI_ISPC = ~0x0;

	_timer = timer;
}
void KeyboardInt(void)
{
	// Esperar trp mediante la funcion DelayMs()*/
	DelayMs(20);
	// Identificar la tecla */
	key_read();
	// Esperar a se libere la tecla: consultar bit 1 del registro de datos del puerto G */
	while ((rPDATG & (1<<1)) == 0 ){
		//NOTHING
	}
	// Esperar trd mediante la funcion Delay() */
	DelayMs(100);
	// Borrar interrupción de teclado */
	rI_ISPC = 1<<24;
}
void key_read()
{
	char temp;
	// Identificar la tecla mediante ''scanning''
	// Si la identificación falla la función debe devolver -1
	temp = *(keyboard_base + 0xfd) & KEY_VALUE_MASK;
	//Usamos KEY_VALUE_MASK para quedarnos con los 4 bits menos significativos

	switch (temp) {
		case 0x7:
			*_timer = 0;
			break;
		case 0xB:
			*_timer = 1;
			break;
		case 0xD:
			*_timer = 2;
			break;
	}
}
