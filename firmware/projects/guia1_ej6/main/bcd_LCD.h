/*! @file bcd_LCD.h
 *  @brief Archivo de cabecera para la gestión del LCD y los números BCD.
 * 
 * Este archivo contiene las declaraciones de las funciones y estructuras necesarias para manejar la conversión
 * de números binarios a BCD y la interacción con el display LCD.
 */

#ifndef BCD_LCD_H
#define BCD_LCD_H

#include <stdint.h>
#include "gpio_mcu.h"   /*!< Incluye la configuración de los GPIO */

/*==================[macros and definitions]=================================*/

/*==================[typedefs and structures]===============================*/

/**
 * @brief Estructura que define un pin GPIO y su dirección.
 */
typedef struct
{
	gpio_t pin; /*!< Número del pin GPIO */
	io_t dir;   /*!< Dirección del pin: 0 para entrada, 1 para salida */
} gpioConf_t;

/*==================[external function declarations]=========================*/

/**
 * @brief Configuración de los pines del GPIO para mostrar un número en el LCD.
 * 
 * @param[in] bcd Número en formato BCD que se va a mostrar.
 * @param[in] config Vector con la configuración de los pines GPIO.
 * @return Devuelve 0 si no hubo errores.
 */
uint8_t ManejoGPIO(uint8_t bcd, gpioConf_t *config);

/**
 * @brief Convierte un número decimal a su representación en BCD.
 * 
 * @param[in] data Número en formato decimal.
 * @param[in] digits Cantidad de dígitos que debe tener el número.
 * @param[out] bcd_number Arreglo donde se almacenará el número en formato BCD.
 * @return Devuelve 0 si no hubo errores.
 */
int8_t BinaryToBcd (uint32_t data, uint8_t digits, uint8_t *bcd_number);

/**
 * @brief Muestra un número en el display LCD utilizando el decodificador BCD.
 * 
 * @param[in] numero Número a mostrar en el display.
 * @param[in] digitos Cantidad de dígitos a mostrar.
 * @param[in] config Vector con la configuración de los pines del LCD.
 * @param[in] seleccion Vector con la selección de los pines de los dígitos.
 * @return No retorna nada.
 */
void ManejoLCD(uint32_t numero, uint8_t digitos, gpioConf_t* config, gpioConf_t* seleccion);

#endif /* BCD_LCD_H */
