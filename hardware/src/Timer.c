#include "stm32h7xx_hal.h"
#include "stdbool.h"
#include "led.h"
#include "buzzer.h"


typedef struct {
    uint32_t time_start;
    uint32_t time_last;
    bool is_runner;
} TIMER;

typedef struct {
    uint32_t on_time;
    uint32_t off_time;
}BUZZER;

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

    static TIMER buzzer_timer;
    static bool buzzer_running = false;                
    static  BUZZER buzzer; 

void buzzer_open(BUZZER *buzzer)
{
   buzzer_on();
    timer_start(&buzzer_timer, buzzer->on_time);
}

void buzzer_stop()
{
    
    buzzer_off();
    timer_stop(&buzzer_timer);
}

static void buzzer_update(BUZZER *buzzer) 
{
    if (!buzzer_timer.is_runner) return;   
    if (expired(&buzzer_timer)) {
        if (buzzer_running) {
            buzzer_off();
            buzzer_running = false;
            timer_start(&buzzer_timer, buzzer->off_time);
        } else {
            buzzer_on();
            buzzer_running = true;
            timer_start(&buzzer_timer, buzzer->on_time);
        }
    }
}
void led_waterflow(uint8_t signal) {
    static TIMER timer;                     
    static uint8_t target_signal = 0xFF;    
    static uint32_t duration = 200;
    static uint8_t led_num = 1U;
    static bool enter_signal = true;
    static TIMER buzzer_timer;
    static bool buzzer_running = false;                 
    static  BUZZER buzzer; 

    
    if (target_signal != signal) {
        led_off_all();                    
        timer_stop(&timer);
        buzzer_stop();               
        target_signal = signal;
        enter_signal = true;
        led_num = 1U;                      
    }

    
    switch (target_signal) {
        case 0:   
            if (enter_signal) {
                led_off_all();
                buzzer_stop();
                timer_stop(&timer);
                enter_signal = false;
            }
            buzzer_running=false;
            break;

        case 1:   
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_num = 1U;
                led_on(led_num);
                buzzer_stop();
            }
            if (expired(&timer)) {
                led_off(led_num);
                led_num++;
                if (led_num > 4U) led_num = 1U;
                led_on(led_num);
                timer_start(&timer, duration);   
            }
            buzzer_running=false;
            break;

        case 2:   
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_num = 1U;
                led_on_double(led_num);
                BUZZER buzzer={200,800};
                buzzer_open(&buzzer);
            }
            if (expired(&timer)) {
                led_off_double(led_num);
                led_num++;
                if (led_num > 2U) led_num = 1U;
                led_on_double(led_num);
                timer_start(&timer, duration);
            }
            BUZZER buzzer1 = {200,800};
                buzzer_update(&buzzer1);
            break;

        case 3:  
            if (enter_signal) {
                timer_start(&timer, duration);
                enter_signal = false;
                led_on_all();                
                led_num = 0U;
                BUZZER buzzer={50,100};
                buzzer_open(&buzzer);

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
            BUZZER buzzer2 = {50,100};
                buzzer_update(&buzzer2);
            break;

        default:
            break;
    }
}