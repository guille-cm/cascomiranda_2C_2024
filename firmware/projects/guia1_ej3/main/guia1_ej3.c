/*! @mainpage Template
 *
 * @section genDesc General Description
 * Este archivo implementa el control de LEDs mediante estructuras, permitiendo encender, apagar o alternar LEDs por un número específico de ciclos con un tiempo definido.
 *
 * @author Casco Miranda
 */

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"

/*==================[macros and definitions]=================================*/

/**
 * @brief Período base para el parpadeo del LED en milisegundos.
 */
#define CONFIG_BLINK_PERIOD 100

/**
 * @brief Modos de operación de los LEDs.
 */
#define ON      1  /**< Enciende el LED */
#define OFF     2  /**< Apaga el LED */
#define TOGGLE  3  /**< Alterna el estado del LED */

/**
 * @brief Cantidad de ciclos de retardo en el parpadeo del LED.
 */
#define COUNT_DELAY 3000000

/*==================[internal data definition]===============================*/

/**
 * @struct t_leds
 * @brief Estructura que contiene los parámetros de control de un LED.
 * 
 * La estructura almacena el número de LED, la cantidad de ciclos, el período de cada ciclo y el modo de operación.
 */
typedef struct {
    uint8_t n_led;      /**< Número del LED a controlar */
    uint8_t n_ciclos;   /**< Cantidad de ciclos encendido/apagado */
    uint32_t periodo;   /**< Tiempo de cada ciclo en milisegundos */
    uint8_t mode;       /**< Modo de operación (ON, OFF, TOGGLE) */
} t_leds;

/*==================[internal functions declaration]=========================*/

/**
 * @brief Controla el estado de un LED en función de la configuración dada.
 * 
 * Esta función controla un LED específico basado en los valores de la estructura `t_leds`. Dependiendo del modo, 
 * puede encender, apagar o alternar el estado del LED durante un número determinado de ciclos.
 * 
 * @param[in] pled Puntero a una estructura `t_leds` que contiene los parámetros del LED a controlar.
 */
void funcion_para_leds (t_leds *pled) {
    switch (pled->mode) {
        case ON: {  /**< Enciende el LED */
            switch (pled->n_led) {
                case 1:
                    LedOn(LED_1);
                    break;
                case 2:
                    LedOn(LED_2);
                    break;
                case 3:
                    LedOn(LED_3);
                    break;
                default:
                    break;
            }
            break;
        }
        case OFF: {  /**< Apaga el LED */
            switch (pled->n_led) {
                case 1:
                    LedOff(LED_1);
                    break;
                case 2:
                    LedOff(LED_2);
                    break;
                case 3:
                    LedOff(LED_3);
                    break;
                default:
                    break;
            }
            break;
        }
        case TOGGLE: {  /**< Alterna el estado del LED */
            uint32_t i;
            for (i = 0; i < 2 * pled->n_ciclos; i++) {
                switch (pled->n_led) {
                    case 1:
                        LedToggle(LED_1);
                        break;
                    case 2:
                        LedToggle(LED_2);
                        break;
                    case 3:
                        LedToggle(LED_3);
                        break;
                    default:
                        break;
                }
                vTaskDelay(pled->periodo / portTICK_PERIOD_MS);  /**< Espera entre los ciclos */
            }
        }
        default:
            break;
    }
}

/*==================[external functions definition]==========================*/

/**
 * @brief Función principal de la aplicación.
 * 
 * Inicializa los LEDs y controla su comportamiento según los parámetros definidos en la estructura `t_leds`.
 */
void app_main(void) {
    LedsInit();  /**< Inicializa los LEDs */
    
    t_leds led_implementado = {1, 10, 500, TOGGLE}; /**< Define los parámetros para el control del LED: número, ciclos, período y modo */
    
    funcion_para_leds(&led_implementado);  /**< Controla el LED según los parámetros */
}

/*==================[end of file]============================================*/
