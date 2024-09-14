
/**
 * @file blinking_switch_2.c
 * @brief Control de titilado de LEDs con teclas. Los LEDs 1 y 2 titilan al presionar teclas 1 y 2, respectivamente. LED 3 titila al presionar simultáneamente las teclas 1 y 2.
 * @author Casco Miranda
 */

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "switch.h"
/*==================[macros and definitions]=================================*/
/** @brief Retardo para hacer que los LEDs titilen */
#define CONFIG_BLINK_PERIOD 1000
/*==================[internal data definition]===============================*/

/*==================[internal functions declaration]=========================*/

/*==================[external functions definition]==========================*/
/**
 * @brief Punto de entrada del programa.
 * 
 * El programa inicializa el sistema y controla el encendido y apagado 
 * de los LEDs según las teclas que se presionen. 
 * - LED 1 titila cuando se presiona la tecla 1.
 * - LED 2 titila cuando se presiona la tecla 2.
 * - LED 3 titila cuando se presionan simultáneamente las teclas 1 y 2.
 * 
 * @return int El programa no debe retornar, se mantiene en bucle infinito.
 */
void app_main(void){
	uint8_t teclas;
	LedsInit();				/**< Inicialización de los LEDs */
	SwitchesInit();			/**< Inicialización de los botones */
    while(1)
    {
        teclas = SwitchesRead();  /**< Lee el estado de las teclas */
        
        switch(teclas)
        {
            /** @brief Tecla 1 presionada: titila el LED 1 */
            case SWITCH_1:
                LedOn(LED_1);
                Delay();
                LedOff(LED_1);
                Delay();
                break;

            /** @brief Tecla 2 presionada: titila el LED 2 */
            case SWITCH_2:
                LedOn(LED_2);
                Delay();
                LedOff(LED_2);
                Delay();
                break;

            /** @brief Teclas 1 y 2 presionadas: titila el LED 3 */
            case (SWITCH_1 | SWITCH_2):
                LedOn(LED_3);
                Delay();
                LedOff(LED_3);
                Delay();
                break;

            default:
                break;
        }
    }

}



