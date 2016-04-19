/*********************************************************************************************
* Fichero:	uart.c
* Autor:	
* Descrip:	funciones de UART
* Version: <P6-ARM-simple>	
*********************************************************************************************/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "uart.h"
#include <stdarg.h>
#include <stdio.h>

void Uart0Rx_ISR(void) __attribute__ ((interrupt ("IRQ")));

/*--- implementación de las funciones ---*/
void Uart_Init(int baud)
{
    /* UART0 */
    rULCON0=0x3;     // Modo normal, no paridad, 1b stop, 8b char
    rUCON0=0x5;    // tx=nivel, rx=flanco, no rx-timeout ni rx-error, normal, int/polling
    rUBRDIV0=( (int)(MCLK/16./baud + 0.5) -1 ); // formula division de frecuencia
    rUFCON0=0x0;     // Desactivar FIFO
    rUMCON0=0x0;	 // Desactivar control de flujo

    /* UART1 */
    rULCON1=0x3;     // Modo normal, no paridad, 1b stop, 8b char
    rUCON1=0x5;    // tx=nivel, rx=flanco, no rx-timeout ni rx-error, normal, int/polling
    rUBRDIV1=( (int)(MCLK/16./baud + 0.5) -1 ); // formula division de frecuencia
    rUFCON1=0x0;	// Desactivar FIFO
    rUMCON1=0x0;	// Desactivar control de flujo

    Uart_Config();
}

void Uart_Config(void)
{
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
	rINTMSK &= ~((1<<7) | (1<<26)); // Habiltar las lineas 21(Eint4567) y 26(bit global)
	// Establecer la rutina de servicio para Eint4567
	pISR_URXD0 = (unsigned) Uart0Rx_ISR;
/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0)
	//rPCONG |= (1<<12 | 1<<13 | 1<<14 | 1<<15);
	//Habilita las resistencias de pull-up
	//rPUPG = 0;
	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT &= ~(1<<30 | 1<<26);
	rEXTINT |= 1<<29 | 1<<25;
/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	rEXTINTPND = ~0x0;
	rI_ISPC = ~0x0;
}

inline void Uart_TxEmpty(void)
{
    while (!(rUTRSTAT1 & 0x4)); 	     // esperar a que el shifter de TX se vacie
}

void Uart0Rx_ISR(void)
{
	 char str[1];
	 char *pt_str = str;

	 *pt_str = Uart_Getch();

	// borra el bit pendiente en INTPND
	rI_ISPC = 1<<7;
}


char Uart_Getch(void)
{
    while (!(rUTRSTAT0 & 0x1));        // esperar a que el buffer contenga datos
	return RdURXH0();		   		   // devolver el caracter
}

void Uart_SendByte(int data)
{
    char localBuf[2] = {'\0','\0'};

    if(data == '\n')		
	{
	   while (!(rUTRSTAT0 & 0x2));     // esperar a que THR se vacie
	   WrUTXH0('\r');			       // escribir retorno de carro (utilizar macro)
	}
	while (!(rUTRSTAT0 & 0x2)); 	   // esperar a que THR se vacie
	WrUTXH0(data);				       // escribir data (utilizar macro)
}

void Uart_SendString(char *pt)
{
    while (*pt)						    // mandar byte a byte hasta completar string
	Uart_SendByte(*pt++);
}

void Uart_Printf(char *fmt,...)
{
    va_list ap;
    char string[256];

    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    Uart_SendString(string);
    va_end(ap);
}



