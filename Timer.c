
#include "Timer.h"
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
