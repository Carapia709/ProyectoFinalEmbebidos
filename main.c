#include "SysTick.h"
#include "Motores.h"
#include "GPIOx.h"
#include <stdint.h>
#include "tm4c1294ncpdt.h"

int main(void){

    SysTick_Init(); // inicializa el SysTick
    GPIOxClockConfig(); // da reloj a los puertos
    GPIOxIOConfig(); // realiza la configuración necesaria de los GPIOS

    int i = 0;

    MotoresDir(0x00);// el motor gira a la derecha

    while(1){

        for(i = 0; i<201; i++){

            MotoresStep('A', 0x02); //para que se envie el paso
            SysTick_Wait(160000);//retardo 40 ms
            MotoresStep('A', 0x02);//para que el step sea 0 y se hagan pulsos
            SysTick_Wait(640000);//retardo 40 ms
        }

    }

}
