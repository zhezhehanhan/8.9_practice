/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"
#define led_left (LED1_PIN|LED2_PIN)
#define led_right (LED3_PIN|LED4_PIN)
#define led_all (LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN)

/* 点亮指定编号的 LED */
void led_on(uint8_t led_num)
{
    switch(led_num)
    {
        case 0:
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
        break;
        case 1:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_SET);
            break;
        default:
            break;
    }
}

/* 熄灭指定编号的 LED */
void led_off(uint8_t led_num)
{
    switch(led_num)
    {
        case 0:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}
void led_on_double(uint8_t led_num)
{
    switch(led_num)
    {
       case 1:
      HAL_GPIO_WritePin(LED_GPIO_PORT,led_right,GPIO_PIN_SET);
      break;
      case 2:
       HAL_GPIO_WritePin(LED_GPIO_PORT,led_left,GPIO_PIN_SET);
       break;
       default:
         break;
    }
}
void led_off_double(uint8_t led_num)
{
    switch(led_num)
    {
       case 1:
      HAL_GPIO_WritePin(LED_GPIO_PORT,led_right,GPIO_PIN_RESET);
      break;
      case 2:
       HAL_GPIO_WritePin(LED_GPIO_PORT,led_left,GPIO_PIN_RESET);
       break;
       default:
         break;
    }
}
void led_on_all(uint8_t led_num)
{
    switch(led_num)
    {
       case 1:
      HAL_GPIO_WritePin(LED_GPIO_PORT,led_all,GPIO_PIN_SET);
      break;
       default:
         break;
    }
}
void led_off_all(uint8_t led_num)
{
    switch(led_num)
    {
       case 1:
      HAL_GPIO_WritePin(LED_GPIO_PORT,led_all,GPIO_PIN_RESET);
      break;
       default:
         break;
    }
}
