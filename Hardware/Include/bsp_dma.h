#ifndef _BSP_DMA_H
#define _BSP_DMA_H

#include "gd32f4xx.h"
#include "systick.h"

/* USART0_RX DMA1_CH2 */
#define BSP_DMA_RCU             RCU_DMA1                    //DMA时钟
#define BSP_DMA                 DMA1                    
#define BSP_DMA_CH              DMA_CH2                     //DMA通道
#define BSP_DMA_CH_IRQ          DMA1_Channel2_IRQn          //DMA中断
#define BSP_DMA_CH_IRQ_HANDLER  DMA1_Channel2_IRQHandler    //DMA中断服务函数

void dma_config(void);

#endif  /* _BSP_DMA_H */