#include "s3cev40.h"
#include "common_types.h"
#include "at24c04.h"

extern void DelayMs(int ms_time);
extern void sys_init();
extern void iic_init();
extern void D8Led_symbol(int value);
extern void at24c04_bytewrite( uint16 addr, uint8 data );
extern void at24c04_byteread( uint16 addr, uint8 *data );

int val;

void Main( void )
{
    //uint8 buffer[AT24C04_DEPTH];
    //uint16 i;
    
	uint* frag = malloc(sizeof(uint));	*frag = 0;
	
	uint* dir1MasSig = malloc(sizeof(uint));	*dir1MasSig = 0;
	uint* dir2MenSig = malloc(sizeof(uint));	*dir2MenSig = 0;
	
	uint* dato1MasSig = malloc(sizeof(uint));	*dato1MasSig = 0;
	uint* dato2MenSig = malloc(sizeof(uint));	*dato2MenSig = 0;	
	
    sys_init();
    iic_init();
    D8Led_symbol(8);//8
	keyboard_init(frag);
	Eint4567_init(frag,dir1MasSig,dir2MenSig,dato1MasSig,dato2MenSig);

    /*for( i=0; i<AT24C04_DEPTH; i++ ){
      val = (uint8)i%4;
      golden_at24c04_bytewrite( i, val );
    }

    //Inicializamos la EEPROM
    for( i=0; i<AT24C04_DEPTH; i++ ){
      val = (uint8)i%16;
      at24c04_bytewrite( i, val );
    }

    /*for( i=0; i<AT24C04_DEPTH; i++ ){
      at24c04_byteread( i, &buffer[i] );
    }

    DelayMs(100);*/

    /*for( i=0; i<AT24C04_DEPTH; i++ ){
      at24c04_byteread( i, &buffer[i] );
      val = buffer[i] & 0xF;
      D8Led_symbol(val);
      DelayMs(100);
    }*/

    while( 1 );
}
