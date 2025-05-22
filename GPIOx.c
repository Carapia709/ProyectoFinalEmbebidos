#include "GPIOx.h"

//FUNCIÓN QUE DA RELOJ A LOS GPIO NECESARIOS PARA EL PROYECTO
void GPIOxClockConfig(void){

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14; // activa reloj puerto Q
    while((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R14) == 0);//Espera hasta que el reloj del GPIO este listo
}

//FUNCIÓN QUE REALIZA LA CONFIGURACIÓN NECESARIA DE LOS GPIOS
void GPIOxIOConfig(void){

    //***************************** CONFIGURACIÓN PUERTOS Q0 Y Q1 *********************************

    GPIO_PORTQ_DIR_R = 0x03;//pone como salidas Q0 y Q1
    GPIO_PORTQ_DEN_R = 0x03;//habilita el puerto digital de Q0 y Q1

    //***************************** CONFIGURACIÓN PUERTOS Q0 Y Q1 *********************************
}
