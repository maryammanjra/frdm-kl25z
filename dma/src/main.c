#include "MKL25Z4.h"
#include "dma.h"

int main(void) {
    SystemInit();     
    Init_DMA_To_Copy(); 

    Test_DMA_Copy();

    while(1) {
    }

    return 0; 
}
