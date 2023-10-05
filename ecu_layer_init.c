
/* 
 * File:   ecu_layer_init.c
 * Author: Abdallah Saad
 * Created on February 7, 2021, 10:39 PM
 */

#include "ecu_layer_init.h"


void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
//    ret = keypad_initialize(&keypad1) ; 
//    ret = lcd_8bit_intialize(&lcd1) ; 
//    ret = led_initialize(&led1) ; 
//    ret = led_initialize(&led2) ; 
//    ret = led_initialize(&led3) ; 
    ret = led_initialize(&room_1) ; 
    ret = led_initialize(&room_2) ; 
    ret = led_initialize(&room_3) ; 
    ret = led_initialize(&room_4) ; 
    ret = led_initialize(&TV) ; 
    ret = led_initialize(&COND) ; 
   
    

}