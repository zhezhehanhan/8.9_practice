#include "led.h"

void led_flow(int mode)
{
    uint8_t led_num = 1U;
    
    
        switch( mode)
        {
            case 1:
             while(led_num <=4U)
                    {
                    led_blink(led_num);
                    led_num++;
                    }
                    break;
            case 2:
            while(led_num<=2)
            {
                led_blink_double(led_num);
                led_num++;
            }
            break;
            case 3:
            while(1)
            {
                led_blink_all(led_num);
            }
            break;
            default:
            break;


        }

       
    
}