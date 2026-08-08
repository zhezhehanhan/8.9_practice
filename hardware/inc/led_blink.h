#ifndef LED_BLINK_H
#define LED_BLINK_H

#include "led.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint16_t led_num;
    uint16_t on_ms;
    uint16_t off_ms;
} led_config;
void led_blink(uint8_t led_num);
void led_blink_double(uint8_t led_num);
void led_blink_all(uint8_t led_num);
#ifdef __cplusplus
}
#endif

#endif
