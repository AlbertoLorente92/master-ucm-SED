#include "visualizacion.h"


void init_visualizacion(void){
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
}

