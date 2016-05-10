/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
#include "playerMovement.h"
#include "bombLogic.h"

extern void D8Led_symbol(int value);
extern int key_read();

void timer_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer_init();

void timer_init(){
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
	rTCFG0 = 0xFF40;
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
	
	/*
	//Establecer manual updates
	rTCON |= (0x1<<1 | 0x1<<9 | 0x1<<13);
	//Desactivar manual updates
	rTCON &= ~(0x1<<1 | 0x1<<9 | 0x1<<13);
	//Activar auto-reload
	rTCON |= (0x1<<3 | 0x1<<11 | 0x1<<15);
	//Iniciar timer
	rTCON |= (0x1<<0 | 0x1<<8 | 0x1<<12);
	*/

	rTCON |= (0x1<<1);
	rTCON &= ~(0x1<<1);
	rTCON |= (0x1<<3);
	rTCON |= (0x1<<0);
}

void timer_ISR(void){
	if ( ((rI_ISPR & BIT_TIMER0)!=0)){
		int aux = key_read();

		if (aux == 1)
			movePlayerUp();
		if (aux == 4)
			movePlayerLeft();
		if (aux == 5)
			movePlayerDown();
		if (aux == 6)
			movePlayerRight();

		redrawChanging();

		D8Led_symbol(aux);

		rI_ISPC = BIT_TIMER0;

		ledsToggle();
	}


	if ( ((rI_ISPR & BIT_TIMER2)!=0)){
		rTCON &= ~(0x1<<12);
		boomBomb(0);
		rI_ISPC = BIT_TIMER2;
	}

	rI_ISPC = BIT_TIMER1;
}
