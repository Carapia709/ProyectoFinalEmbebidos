#include <stdint.h>
#include "tm4c1294ncpdt.h"

//FUNCION PARA INICIALIZAR EL SYSTICK
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // Desahabilita el SysTick durante la configuracion
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // Se establece el valor de cuenta deseado en RELOAD_R
  NVIC_ST_CURRENT_R = 0;                // Se escribe al registro current para limpiarlo

  NVIC_ST_CTRL_R = 0x00000005;         // Se Habilita el SysTick y se selecciona la fuente de reloj (EL BIT 2, 1-->16MHz ; 0-->4MHz)
}

//FUNCIONES PARA CREAR RETARDOS CON EL SYSTICK
void SysTick_Wait(uint32_t retardo){
    NVIC_ST_RELOAD_R= retardo-1;   //numero de cuentas por esperar
    NVIC_ST_CURRENT_R = 0;
    while((NVIC_ST_CTRL_R&0x00010000)==0){//espera hasta que la bandera COUNT sea valida
    }
   }

int main(void){

    SysTick_Init();// inicializa el SysTick

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14; // activa reloj puerto Q
    while((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R14) == 0);//Espera hasta que el reloj del GPIO este listo

    GPIO_PORTQ_DIR_R = 0x03;//pone como salidas Q0 y Q1
    GPIO_PORTQ_DEN_R = 0x03;//habilita el puerto digital de Q0 y Q1

    int i = 0;

    GPIO_PORTQ_DATA_R = 0x00;//para que gire a la derecha

    while(1){

        for(i = 0; i<201; i++){

            GPIO_PORTQ_DATA_R = 0x02;//para que se envie el paso
            SysTick_Wait(160000);//retardo 40 ms
            GPIO_PORTQ_DATA_R = 0x00;//para que el step sea 0 y se hagan pulsos
            SysTick_Wait(640000);//retardo 40 ms
        }

    }

}
