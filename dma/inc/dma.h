#ifndef DMA_H
#define DMA_H

#include <stdint.h>

#define ARR_SIZE 256

extern uint32_t s[ARR_SIZE];
extern uint32_t d[ARR_SIZE];

void Init_DMA_To_Copy(void);
void Copy_Longwords(uint32_t *source, uint32_t *dest, uint32_t count);
void Test_DMA_Copy(void);

#endif 
