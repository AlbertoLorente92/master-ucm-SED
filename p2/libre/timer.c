/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
/*--- funciones externas ---*/
extern void D8Led_symbol(int value);
/*--- declaracion de funciones ---*/
void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer_init(int* count, int* dir, int* timer);
/*--- codigo de las funciones ---*/

int* _count;
int* _dir;
int* _timer;

void timer_init(int* count, int* dir, int* timer)
{
	// Configuracion del controlador de interrupciones */
	// Configura las lineas como de tipo IRQ mediante INTMOD
	rINTMOD = 0x0;
	// Habilitar int. vectorizadas y la linea IRQ (FIQ no)
	rINTCON &= ~(0x1<<1 | 0x1<<2);
	rINTCON |= 0x1<<0;
	//Habilitar linea de timer [0..2] y bit global
	rINTMSK &= ~(1<<13 | 1<<12 | 1<<11 | 1<<26);
	//rINTMSK = rINTMSK & ~(BIT_TIMER0 | BIT_GLOBAL);// Enmascarar todas las lineas excepto Timer0 y el bit global
	// Establece la rutina de servicio para TIMER [0..2] */
	pISR_TIMER0 = (unsigned)timer_ISR;
	pISR_TIMER1 = (unsigned)timer_ISR;
	pISR_TIMER2 = (unsigned)timer_ISR;

	//Configurar Timer [0..2]
	//Configurar prescales's 0 y 1
	rTCFG0 = 0xFFFF;
	//Limiar divisores [0..2]
	rTCFG1 &= ~((unsigned int)0x0)<<12;
	//Fijar divisor 0
		// Ya fijado
	//Fijar divisor 1
	rTCFG1 |= 0x2<<4;
	//Fijar divisor 2
	rTCFG1 |= 0x4<<8;

	rTCNTB0=65535;
	rTCNTB1=65535;
	rTCNTB2=65535;
	rTCMPB0=12800;
	rTCMPB1=12800;
	rTCMPB2=12800;
	
	//Establecer manual updates
	rTCON |= (0x1<<1 | 0x1<<9 | 0x1<<13);
	//Desactivar manual updates
	rTCON &= ~(0x1<<1 | 0x1<<9 | 0x1<<13);
	//Activar auto-reload
	rTCON |= (0x1<<3 | 0x1<<11 | 0x1<<15);
	//Iniciar timer
	rTCON |= (0x1<<0 | 0x1<<8 | 0x1<<12);

	_count = count;
	_dir = dir;
	_timer = timer;
}

void timer_ISR(void){
	if ( ((rI_ISPR & BIT_TIMER0)!=0) && *_timer==0 ){
		*_count += *_dir;
		*_count &= ((unsigned int)(~0x0))>>(32-4);
		D8Led_symbol(*_count);
	}
	if ( ((rI_ISPR & BIT_TIMER1)!=0) && *_timer==1 ){
		*_count += *_dir;
		*_count &= ((unsigned int)(~0x0))>>(32-4);
		D8Led_symbol(*_count);
	}
	if ( ((rI_ISPR & BIT_TIMER2)!=0) && *_timer==2 ){
		*_count += *_dir;
		*_count &= ((unsigned int)(~0x0))>>(32-4);
		D8Led_symbol(*_count);
	}
	rI_ISPC = BIT_TIMER0 | BIT_TIMER1 | BIT_TIMER2 ;
}
