/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
/*--- definicion de macros ---*/
/* Mapa de bits de cada segmento
(valor que se debe escribir para que se ilumine el segmento) */
#define SEGMENT_A 0x7F
#define SEGMENT_B 0xBF
#define SEGMENT_C 0xDF 
#define SEGMENT_DP 0xE
#define SEGMENT_D 0xF7 
#define SEGMENT_E 0xFB 
#define SEGMENT_F 0xFD 
#define SEGMENT_G 0xFE 
#define SEGMENT_P 0xEF 

/*--- variables globales ---*/
/* tabla de segmentos */
int Symbol[] = { 
	SEGMENT_A & SEGMENT_B & SEGMENT_C & SEGMENT_D & SEGMENT_E & SEGMENT_G, 	//0
	SEGMENT_B & SEGMENT_C,							//1
	SEGMENT_A & SEGMENT_B & SEGMENT_F & SEGMENT_E & SEGMENT_D,		//2
	SEGMENT_A & SEGMENT_B & SEGMENT_F & SEGMENT_C & SEGMENT_D,		//3
	SEGMENT_G & SEGMENT_F & SEGMENT_B & SEGMENT_C,				//4
	SEGMENT_A & SEGMENT_G & SEGMENT_F & SEGMENT_C & SEGMENT_D		//5
	~(SEGMENT_B & SEGMENT_DP),						//6
	SEGMENT_A & SEGMENT_B & SEGMENT_C,					//7
	~(SEGMENT_DP),								//8
	~(SEGMENT_E & SEGMENT_DP),						//9
	~(SEGMENT_D & SEGMENT_DP),						//A
	~(SEGMENT_A & SEGMENT_B & SEGMENT_DP),					//b
	~(SEGMENT_B & SEGMENT_C & SEGMENT_DP),					//C
	~(SEGMENT_A & SEGMENT_G & SEGMENT_DP),					//D
	~(SEGMENT_B & SEGMENT_C & SEGMENT_DP),					//E
	~(SEGMENT_B & SEGMENT_C & SEGMENT_D & SEGMENT_DP),			//F
};

/*--- declaracion de funciones ---*/
void D8Led_init(void);
void D8Led_symbol(int value);
/*--- codigo de las funciones ---*/
void D8Led_init(void)
{
/* Estado inicial del display con todos los segmentos iluminados
(buscar en los ficheros de cabecera la direccion implicada--->44blib.h) */
	LED8ADDR = 0; 
}
void D8Led_symbol(int value)
{
// muestra Symbol[value] en el display
	LED8ADDR=Symbol[value];
}
