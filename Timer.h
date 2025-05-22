#ifndef __TIMER_H
#define __TIMER_H

#include <stdint.h>

void SysTick_Init(void);

void SysTick_Wait(uint32_t retardo);

#endif // __TIMER_H