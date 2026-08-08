#include "led.h"

void led_flow(void)
{
    uint8_t led_num = 1U;
    uint16_t delay_time = 200U;
    while(1)
    {
        led_num = 1U;
        while(led_num <=4U)
        {
        
        led_on(led_num);
        HAL_Delay(delay_time);  
        led_off(led_num);
        led_num++;
    }
    }
}