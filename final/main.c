/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "uart.h"
#include "lcd.h"

/*--- declaracion de funciones ---*/
int Main(void);

int Main(void){
	sys_init(); // inicializacion de la placa, interrupciones, puertos
	Uart_Init(115200); // inicializacion de la Uart

	lcd_init();
	lcd_clear();
	int j;
	for(j = 0; j < 320; j++){
		lcd_putpixel(j,1,LIGHTGRAY);
		lcd_putpixel(j,2,LIGHTGRAY);
		lcd_putpixel(j,3,LIGHTGRAY);
		lcd_putpixel(j,4,LIGHTGRAY);
		lcd_putpixel(j,5,LIGHTGRAY);
		lcd_putpixel(j,6,LIGHTGRAY);

		lcd_putpixel(j,8,DARKGRAY);
		lcd_putpixel(j,9,DARKGRAY);
		lcd_putpixel(j,10,DARKGRAY);



	//	lcd_putpixel(j,11,BLACK);
		lcd_putpixel(j,12,BLACK);
		lcd_putpixel(j,13,BLACK);
		lcd_putpixel(j,14,BLACK);
		lcd_putpixel(j,15,BLACK);
		lcd_putpixel(j,14,BLACK);
	}

	while(1){
	}
	return 0;
}
