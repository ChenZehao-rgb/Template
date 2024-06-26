#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "gd32f4xx.h"
#include "systick.h"

#define RCU_LED2        RCU_GPIOD    // LED时钟
#define PORT_LED2       GPIOD
#define PIN_LED2        GPIO_PIN_7

void led_gpio_config(void);

#endif // __BSP_LED_H