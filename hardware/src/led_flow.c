#include "led.h"
#include "Timer.h"
void led_flow(int mode)
{
    uint8_t led_num = 1U;
    
    
        switch( mode)
        {
            case 0:
            led_off_all();
            break;
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
                led_blink_all();
            }
            break;
            default:
            break;


        }

       
    
}
