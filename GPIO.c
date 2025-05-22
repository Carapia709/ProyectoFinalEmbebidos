#include "GPIO.h"
#include "tm4c1294ncpdt.h"
#include <stdint.h>

void GPIO_Init(){
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14; // activa reloj puerto Q
    while((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R14) == 0);//Espera hasta que el reloj del GPIO este listo

    GPIO_PORTQ_DIR_R = 0x03;//pone como salidas Q0 y Q1
    GPIO_PORTQ_DEN_R = 0x03;//habilita el puerto digital de Q0 y Q1

    
    GPIO_PORTQ_DATA_R = 0x00;//para que gire a la derecha
}

void SetGPIO(bool On){
    if (On)
    {
        GPIO_PORTQ_DATA_R = 0x02;//para que se envie el paso
    }
    else
    {
        GPIO_PORTQ_DATA_R = 0x00;//para que el step sea 0 y se hagan pulsos
    }
}