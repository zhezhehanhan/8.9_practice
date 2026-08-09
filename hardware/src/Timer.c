#include "stm32h7xx_hal.h"
#include "stdbool.h"
#include "led.h"


typedef struct {
    uint32_t time_start;
    uint32_t time_last;
    bool is_runner;
} TIMER;


void timer_start(TIMER *timer, uint32_t duration) {
    timer->time_start = HAL_GetTick();
    timer->time_last = duration;
    timer->is_runner = true;
}

void timer_stop(TIMER *timer) {
    timer->is_runner = false;
}


static bool expired(TIMER *timer) {
    if (!timer->is_runner) {
        return false;
    }
    uint32_t elapsed = HAL_GetTick() - timer->time_start;   
    if (elapsed >= timer->time_last) {
        timer->is_runner = false;   
        return true;
    }
    return false;
}

void led_waterflow(uint8_t signal) {
    static TIMER timer;                     
    static uint8_t target_signal = 0xFF;    
    static uint32_t duration = 200;
    static uint8_t led_num = 1U;
    static bool enter_signal = true;

    
    if (target_signal != signal) {
        led_off_all();                    
        timer_stop(&timer);               
        target_signal = signal;
        enter_signal = true;
        led_num = 1U;                      
    }

    
    switch (target_signal) {
        case 0:   
            if (enter_signal) {
                led_off_all();
                timer_stop(&timer);
                enter_signal = false;
            }
            break;

        case 1:   
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_num = 1U;
                led_on(led_num);
            }
            if (expired(&timer)) {
                led_off(led_num);
                led_num++;
                if (led_num > 4U) led_num = 1U;
                led_on(led_num);
                timer_start(&timer, duration);   
            }
            break;

        case 2:   
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_num = 1U;
                led_on_double(led_num);
            }
            if (expired(&timer)) {
                led_off_double(led_num);
                led_num++;
                if (led_num > 2U) led_num = 1U;
                led_on_double(led_num);
                timer_start(&timer, duration);
            }
            break;

        case 3:  
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_on_all();                
                led_num = 0U;               
            }
            if (expired(&timer)) {
                if (led_num == 0U) {
                    led_off_all();           
                    led_num = 1U;
                } else {
                    led_on_all();           
                    led_num = 0U;
                }
                timer_start(&timer, duration);   
            }
            break;

        default:
            break;
    }
}