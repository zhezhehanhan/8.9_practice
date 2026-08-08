#include "led.h"

typedef struct
{
    uint8_t led_num;
    uint16_t on_ms;
    uint16_t off_ms;
} led_config;
static led_config led_cfg={1U,200U,200U};
/*单个LED灯点亮控制*/
void led_blink(led_num)
{led_cfg.led_num=led_num;
    led_on(led_cfg.led_num);
    HAL_Delay(led_cfg.on_ms);
    led_off(led_cfg.led_num);
    HAL_Delay(led_cfg.off_ms);    
}
/*两两LED灯同时控制*/
void led_blink_double(led_num)
{led_cfg.led_num=led_num;
    led_on_double(led_cfg.led_num);
    HAL_Delay(led_cfg.on_ms);
    led_off_double(led_cfg.led_num);
    HAL_Delay(led_cfg.off_ms);    
}
/*所有LED灯同时控制*/
void led_blink_all(led_num)
{led_cfg.led_num=led_num;
    led_on_all(led_cfg.led_num);
    HAL_Delay(led_cfg.on_ms);
    led_off_all(led_cfg.led_num);
    HAL_Delay(led_cfg.off_ms);    
}