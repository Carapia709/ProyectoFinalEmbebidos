#include <stdint.h>
#include "GPIO.h"

int main(void){

    SysTick_Init();// inicializa el SysTick

    int i = 0;

    while(1){

        for(i = 0; i<201; i++){

            SetGPIO(true);
            SysTick_Wait(160000);//retardo 40 ms
            SetGPIO(false);
            SysTick_Wait(640000);//retardo 40 ms
        }

    }

}
