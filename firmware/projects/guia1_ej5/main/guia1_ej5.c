/*! @mainpage Conversion de un numero decimal a BCD
 *
 * \section genDesc General Description
 *
 *
 * @author Guillermo Casco Miranda guillermo.casco.miranda@gmail.com
 *
 */
/*==================[inclusions]=============================================*/
#include "gpio_mcu.h"  /*!< Incluye la cabecera correspondiente */
#include <stdint.h>

/*==================[macros and definitions]=================================*/

/*==================[internal data definition]===============================*/
/**
 * @brief Estructura que define la configuración de un GPIO.
 * 
 * Contiene el número de pin GPIO y su dirección (entrada o salida).
 */
typedef struct
{
    gpio_t pin;  /*!< Número de pin GPIO */
    io_t dir;    /*!< Dirección del GPIO ('0' IN, '1' OUT) */
} gpioConf_t;

/*==================[internal functions declaration]=========================*/
/**
 * @fn uint8_t ManejoGPIO(uint8_t bcd, gpioConf_t *config)
 * @brief Configuración de los GPIO basados en el valor del dígito BCD.
 * 
 * La función configura los pines GPIO según el valor de cada bit del dígito BCD recibido. Cada bit 
 * del BCD se asigna a un GPIO diferente y establece su estado en ALTO o BAJO.
 * 
 * @param[in] bcd Dígito en BCD cuyo estado de bits se refleja en los GPIO.
 * @param[in] config Vector de estructuras que contiene la configuración de cada pin GPIO (pin y dirección).
 * @return uint8_t Retorna 0 si no hay errores.
 */
uint8_t ManejoGPIO(uint8_t bcd, gpioConf_t *config) {
    for (int i = 0; i < 4; i++) {
        GPIOInit(config[i].pin, config[i].dir);  /*!< Inicializa el GPIO con la configuración adecuada */
        
        if (bcd & (1 << i)) {  /*!< Si el bit 'i' del BCD está en 1, enciende el GPIO correspondiente */
            GPIOOn(config[i].pin);
        } else {               /*!< Si el bit 'i' del BCD está en 0, apaga el GPIO correspondiente */
            GPIOOff(config[i].pin);
        }
    }
    return 0;  /*!< Retorna 0 indicando que no hubo errores */
}

/*==================[external functions definition]==========================*/
/**
 * @brief Función principal del programa.
 * 
 * Configura los GPIOs basados en los bits del BCD, mapeando los pines GPIO_20, GPIO_21, 
 * GPIO_22 y GPIO_23 a los bits correspondientes de un dígito BCD.
 * 
 * @return void
 */

void app_main(void){

	/* Definición del vector de configuración, mapeando los bits del BCD a los GPIO correspondientes */
    gpioConf_t conf[4] = {
        {GPIO_20, GPIO_OUTPUT},  /*!< b0 -> GPIO_20 */
        {GPIO_21, GPIO_OUTPUT},  /*!< b1 -> GPIO_21 */
        {GPIO_22, GPIO_OUTPUT},  /*!< b2 -> GPIO_22 */
        {GPIO_23, GPIO_OUTPUT}   /*!< b3 -> GPIO_23 */
    };

    /* Manejo de diferentes valores de BCD para establecer el estado de los GPIO */
    ManejoGPIO(4, conf);  /*!< Establece el estado del BCD 4 */
    ManejoGPIO(6, conf);  /*!< Establece el estado del BCD 6 */
    ManejoGPIO(9, conf);  /*!< Establece el estado del BCD 9 */

    while (1) {
        /* Bucle infinito */
    }
}
/*==================[end of file]============================================*/