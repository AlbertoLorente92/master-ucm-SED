#include "at24c04.h"
#include "iic.h"

void at24c04_bytewrite( uint16 addr, uint8 data )
{
	uint8 page;
	
	page = (addr & 0x100) >> 8;	// Extrae el n�mero de p�gina 

	/*A�adir el prefijo golden_ para usar la versi�n de test. Ej. golden_iic_putByte_start*/
	iic_putByte_start( (AT24C04_ADDRESS << 2) | (page << 1) | AT24C04_WRITE );
	iic_putByte( addr & 0xFF );
	iic_putByte_stop( data );
}
	
void at24c04_byteread( uint16 addr, uint8 *data )
{
	uint8 page;
	
	page = (addr & 0x100) >> 8;	// Extrae el n�mero de p�gina 
	
	iic_putByte_start( (AT24C04_ADDRESS << 2) | (page << 1) | AT24C04_WRITE );  // Lleva el contador de direcci�n de la EEPROM a la direcci�n indicada
	iic_putByte( addr & 0xFF );
	iic_getByte_start( (AT24C04_ADDRESS << 2) | (page << 1) | AT24C04_READ );
	*data = iic_getByte_stop( NO_RxACK ); 								// En una EEPROM, no debe generarse ACK tras el �ltimo dato recibido
}