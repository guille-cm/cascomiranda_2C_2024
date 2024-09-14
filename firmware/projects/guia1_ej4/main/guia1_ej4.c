/*! @mainpage Conversion de un numero decimal a BCD
 *
 * \section genDesc General Description
 *
 *
 * @author Guillermo Casco Miranda guillermo.casco.miranda@gmail.com
 *
 */
/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdint.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data definition]===============================*/

/*==================[internal functions declaration]=========================*/

/** @fn int8_t BinaryToBcd (uint32_t data, uint8_t digits, uint8_t *bcd_number)
 * @brief Conversion de un decimal de 32 bit, con n digitos,
 * a un arreglo de enteros de 8 bits, en bcd
 * @param[in] decimal número, número de dígitos, puntero pasado por referencia
 * @return return FALSE if no error
 */
int8_t BinaryToBcd (uint32_t data, uint8_t digits, uint8_t *bcd_number){
	unsigned int i;
	for(i=digits;i>0;i--){
		bcd_number[i]=data%10;
		data=data/10;
	}
	return 0;
}

/*==================[external functions definition]==========================*/

/**
 * @brief Punto de entrada del programa.
 * 
 * El programa covierte un decimal a BCD
 * 
 * @return void
 */
void app_main(void){
	/* initializations */
	
	uint32_t datos=1234;
	uint8_t digitos=4;
	uint8_t bcd[digitos];


	
    while(1){
		/* main loop */
    	BinaryToBcd(datos,digitos,bcd);
    	for(int i=0;i<50000;i++){};
	}
}
/*==================[end of file]============================================*/