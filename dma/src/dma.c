#include <stdint.h>
#include "MKL25Z4.h"

#define ARR_SIZE (256) 
uint32_t s[ARR_SIZE], d[ARR_SIZE];

void Init_DMA_To_Copy(void) { 
    SIM->SCGC7 |= SIM_SCGC7_DMA_MASK; 
    DMA0->DMA[0].DCR = DMA_DCR_SINC_MASK | DMA_DCR_SSIZE(0) | DMA_DCR_DINC_MASK | DMA_DCR_DSIZE(0); 
} 

void Copy_Longwords(uint32_t * source, uint32_t * dest, uint32_t count) { 
    DMA0->DMA[0].SAR = DMA_SAR_SAR((uint32_t) source); 
    DMA0->DMA[0].DAR = DMA_DAR_DAR((uint32_t) dest); 
    DMA0->DMA[0].DSR_BCR = DMA_DSR_BCR_BCR(count*4); 
    DMA0->DMA[0].DSR_BCR &= ~DMA_DSR_BCR_DONE_MASK; 
    DMA0->DMA[0].DCR |= DMA_DCR_START_MASK; 
    while (!(DMA0->DMA[0].DSR_BCR & DMA_DSR_BCR_DONE_MASK));
} 

void Test_DMA_Copy(void) {
    uint16_t i;
    Init_DMA_To_Copy(); 
    for (i=0; i<ARR_SIZE; i++) { 
        s[i] = i; 
        d[i] = 0; 
    } 
    Copy_Longwords(s, d, ARR_SIZE);
}
