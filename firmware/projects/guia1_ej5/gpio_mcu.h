#ifndef GPIO_MCU_H
#define GPIO_MCU_H

#include <stdint.h>

/*==================[macros and definitions]=================================*/

/** @brief Define el tipo de datos para los pines GPIO */
typedef uint32_t gpio_t;  /*!< Define los pines GPIO como un entero de 32 bits */

/** @brief Define el tipo de datos para la dirección de los pines GPIO */
typedef enum {
    GPIO_INPUT = 0,  /*!< Modo de entrada (0) */
    GPIO_OUTPUT = 1  /*!< Modo de salida (1) */
} io_t;

/*==================[external function declarations]=========================*/

/**
 * @brief Inicializa un pin GPIO.
 * 
 * Configura un pin GPIO específico con la dirección dada (entrada o salida).
 * 
 * @param[in] pin Número del pin GPIO.
 * @param[in] dir Dirección del pin (GPIO_INPUT o GPIO_OUTPUT).
 */
void GPIOInit(gpio_t pin, io_t dir);

/**
 * @brief Activa un pin GPIO (pone el pin en estado ALTO).
 * 
 * @param[in] pin Número del pin GPIO.
 */
void GPIOOn(gpio_t pin);

/**
 * @brief Desactiva un pin GPIO (pone el pin en estado BAJO).
 * 
 * @param[in] pin Número del pin GPIO.
 */
void GPIOOff(gpio_t pin);

#endif /* GPIO_MCU_H */
