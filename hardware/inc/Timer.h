#ifndef TIMER_H
#define TIMER_H

#include "stm32h7xx_hal.h"
#include"stdbool.h"

typedef struct
{
    uint32_t time_start;
    uint32_t time_last;
    bool is_runner;
} TIMER;
typedef struct {
    uint32_t on_time;
    uint32_t off_time;
}BUZZER;
#ifdef __cplusplus
extern "C" {
#endif

void timer_start(TIMER *timer ,uint32_t duration);
static bool expired(TIMER *timer);
void timer_stop(TIMER *timer);
void led_waterflow(uint8_t signal);
void buzzer_open(BUZZER *buzzer);
void buzzer_stop();
static void buzzer_update(BUZZER *buzzer) ;
#ifdef __cplusplus
}
#endif

#endif 