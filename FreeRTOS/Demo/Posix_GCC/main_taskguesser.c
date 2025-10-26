/* -----------------------------------------------------
 * Plantilla para asignación de Minitaller #13 FreeRTOS
 * Autor: Óscar González Cambronero
 * -----------------------------------------------------
 */

#include <stdio.h>
#include <pthread.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "console.h"

/* Tarea1: Imprime un mensaje cada segundo */
void Tarea1(void *parametros)
{
    TickType_t ultimo_cambio;
    const TickType_t delay_en_ticks = pdMS_TO_TICKS(1000);

    ultimo_cambio = xTaskGetTickCount();

    for(;;)
    {
        console_print("Tarea1: Aquí estoy!\n");
        vTaskDelayUntil(&ultimo_cambio, delay_en_ticks);
    }
}

/* Tarea2: Imprime un mensaje cada segundo y medio */
void Tarea2(void *parametros)
{
    TickType_t ultimo_cambio;
    const TickType_t delay_en_ticks = pdMS_TO_TICKS(1500);

    ultimo_cambio = xTaskGetTickCount();

    for(;;)
    {
        console_print("Tarea2: Aquí estoy!\n");
        vTaskDelayUntil(&ultimo_cambio, delay_en_ticks);
    }
}

void main_taskguesser(void)
{
    xTaskCreate(
        Tarea1,              /* Función de la Tarea */
        "Tarea1",             /* Nombre de la Tarea */
        1000,                /* Tamaño del Stack (en palabras, no bytes) */
        NULL,                /* Parámetros de la Tarea */
        1,                   /* Prioridad */
        NULL                 /* Manejador de la Tarea */
    );

    xTaskCreate(
        Tarea2,              /* Función de la Tarea */
        "Tarea2",             /* Nombre de la Tarea */
        1000,                /* Tamaño del Stack (en palabras, no bytes) */
        NULL,                /* Parámetros de la Tarea */
        1,                   /* Prioridad */
        NULL                 /* Manejador de la Tarea */
    );

    /* Inicializar el calendarizador (NO MODIFICAR) */
    vTaskStartScheduler();

    /* Si todo está bien, el calendarizador se está ejecutando, y el programa no
     * debe seguir a la siguiente línea.
     * Si la siguiente línea se ejecuta, entonces
     * no había suficiente memoria en el heap de FreeRTOS disponible para que las tareas
     * fueran creadas.
     */
    for(;;)
    {
    }
}

