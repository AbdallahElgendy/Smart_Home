/* 
 * File:   application.c
 * Author: Abdallah Saad
* Created on August 7, 2022, 10:39 PM
 */

#include "application.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
#include "MCAL_Layer/I2C/hal_i2c.h"
#include "MCAL_Layer/ADC/hal_adc.h"


/*
#define CHECK_ADD_TO_SET 0x3FF 
#define EEPROM_LOCATION0 0x00
#define EEPROM_LOCATION1 0x01
#define EEPROM_LOCATION2 0x02
#define EEPROM_LOCATION3 0x03
#define EEPROM_LOCATION4 0x04
#define EEPROM_LOCATION5 0x05
#define EEPROM_LOCATION6 0x06
#define EEPROM_LOCATION7 0x07
#define slave  0x60 


mssp_i2c_t master_obj = {
    .I2C_DefaultInterruptHandler = NULL , 
    .I2C_Report_Receive_Overflow = NULL , 
    .I2C_Report_Write_Collision = NULL ,  
    .i2c_clock = 100000 ,
    .i2c_cfg.i2c_mode = I2C_MSSP_MASTER_MODE , 
    .i2c_cfg.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK , 
    .i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE , 
    .i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE , 
} ; 

uint8 slave_ack = 0;

void MSSP_I2C_SEND_BYTE(uint8 slave_address, uint8 data) {
    MSSP_I2C_Master_Send_Start(&master_obj);
    MSSP_I2C_Master_Write_Blocking(&master_obj, slave_address, &slave_ack);
    MSSP_I2C_Master_Write_Blocking(&master_obj, data, &slave_ack);
    MSSP_I2C_Master_Send_Stop(&master_obj);
}

uint8 CheckValue ; 
uint8 key1 ,key2 ,key3 ,key4 , key5 ,key6 ,key7 ,key8 ,l_value , flag = 0 ; 
int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    ret = MSSP_I2C_Init(&master_obj) ;  
    ret = Data_EEPROM_ReadByte( CHECK_ADD_TO_SET ,&CheckValue) ; 
    if(CheckValue == 0xFF){
       ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 , "Set admin pass:") ; 
       ret =keypad_get_value_blocking(&keypad1 , &key1) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , key1 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key2) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 17 , key2 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 17 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key3) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 18 , key3 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 18 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key4) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 19 , key4 ) ; 
       __delay_ms(200) ;
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 19 , '*') ; 
       __delay_ms(300) ; 


       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION0 , key1) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION1 , key2) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION2 , key3) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION3 , key4) ; 
       ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
       
       ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 , "Set guest pass:") ; 
       ret =keypad_get_value_blocking(&keypad1 , &key1) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , key1 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key2) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 17 , key2 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 17 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key3) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 18 , key3 ) ; 
       __delay_ms(200) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 18 , '*') ; 
       ret =keypad_get_value_blocking(&keypad1 , &key4) ; 
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 19 , key4 ) ; 
       __delay_ms(200) ;
       ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 19 , '*') ; 
       __delay_ms(300) ; 
       
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION4 , key1) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION5 , key2) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION6 , key3) ; 
       ret = Data_EEPROM_WriteByte(EEPROM_LOCATION7 , key4) ; 
       ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
       ret = Data_EEPROM_WriteByte(CHECK_ADD_TO_SET , 0) ; 
    }
    ret = Data_EEPROM_ReadByte( CHECK_ADD_TO_SET ,&CheckValue) ; 
    if (CheckValue == 0x00){
        label_1 : 
        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
        ret = lcd_8bit_send_string_pos(&lcd1 , 1, 5 , "Welcome Home") ; 
        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 , "You are -> ") ; 
        ret = lcd_8bit_send_string_pos(&lcd1 , 3, 11 , "1 -> Admin ") ; 
        ret = lcd_8bit_send_string_pos(&lcd1 , 4, 11 , "2 -> Guest ") ; 
        
        ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
        if(l_value == '1'){
            for(uint8 i = 0 ; i<3 ; i++){
            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 , "Admin pass: ") ; 
            ret =keypad_get_value_blocking(&keypad1 , &key5) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 13 , key5 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 13 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key6) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 14 , key6 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 14 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key7) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 15 , key7 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 15 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key8) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , key8 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , '*') ; 
            __delay_ms(300) ; 

            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION0 , &key1) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION1 , &key2) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION2 , &key3) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION3 , &key4) ; 
            if((key5 == key1) && (key6 == key2) &&(key7 == key3) &&(key8 == key4)){
                label_2 :
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 1, 2 ,"you are an admin ") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Room1  2- Room2 ") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"3- Room3  4- Room4 ") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"5- Recep  6- Back  ") ;
                
                ret = led_turn_on(&led2) ; 
                ret = led_turn_off(&led1) ; 
                ret = led_turn_off(&led3) ; 
                
                ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                if(l_value == '1'){
                    label_3 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Room 1") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the led ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'a'); 
                        goto label_3 ;  
                    }
                    else if(l_value == '2'){
                        goto label_2 ; 
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_3 ; 
                    }
                    
                }
                else if(l_value == '2'){
                    label_4 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Room 2") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the led ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'b');
                        goto label_4 ;  
                    }
                    else if(l_value == '2'){
                        goto label_2 ; 
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_4 ; 
                    }
                }
                else if(l_value == '3'){
                    label_5 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Room 3") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the led ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'c');
                        goto label_5 ;  
                    }
                    else if(l_value == '2'){
                        goto label_2 ; 
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_5 ; 
                    }
                }
                else if(l_value == '4'){
                    label_6 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Room 4") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the led ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'd');
                        goto label_6 ;  
                    }
                    else if(l_value == '2'){
                        goto label_2 ; 
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_6 ; 
                    }
                } 
                else if(l_value == '5'){
                    label_7 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Reception") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the TV ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- The air COND ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'e');
                        goto label_7 ;  
                    }
                    else if(l_value == '2'){
                        label_10 :
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 1, 3 ,"The air Condition") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Set Temp") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Control ") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                        
                        
                        ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                        if(l_value == '1'){
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"Set Temp :__ C") ;
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 11 ,l_value) ;
                            MSSP_I2C_SEND_BYTE(slave,l_value );
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 12 ,l_value) ;
                            MSSP_I2C_SEND_BYTE(slave , l_value);
                            __delay_ms(500) ;
                            goto label_10 ;
                            
                        }
                        else if(l_value == '2'){
                            label_11 :
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Close COND") ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Open COND") ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            
                            if(l_value == '1'){
                                MSSP_I2C_SEND_BYTE(slave, 'g');
                                goto label_11 ;  
                            }
                            else if(l_value == '2'){
                                MSSP_I2C_SEND_BYTE(slave, 'h');
                                goto label_11 ;  
                            }
                            else if(l_value == '3'){
                                goto label_10 ;
                            }
                            else{
                                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                                __delay_ms(500) ; 
                                goto label_11 ;
                            }
                        }
                        else if(l_value == '3'){
                            goto label_7 ; 
                        }
                        else{
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                            __delay_ms(500) ; 
                            goto label_10 ; 
                        }
                         
                    }
                    else if(l_value == '3'){
                        goto label_2 ; 
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_7 ; 
                    }
                    
                }
                else if (l_value == '6'){
                    ret = led_turn_off(&led2) ; 
                    ret = led_turn_off(&led1) ;
                    ret = led_turn_off(&led3) ;
                    goto label_1 ; 
                }
                else{
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                    __delay_ms(500) ; 
                    goto label_2 ; 
                }
                
            }
            else if( i < 2){
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ," Please try again ") ;
                __delay_ms(500) ; 

            }
            else if (i == 2){
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"U are in block mode") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 3, 7 ," Wait ") ;
                ret = led_turn_on(&led3) ; 
                ret = led_turn_off(&led2) ; 
                ret = led_turn_off(&led1) ;
                __delay_ms(2000) ; 
                ret = led_turn_off(&led2) ; 
                ret = led_turn_off(&led1) ;
                ret = led_turn_off(&led3) ;
                i =  -1 ; ;
                
            }
        }
            
        }
        else if(l_value == '2'){
            for(uint8 i = 0 ; i<3 ; i++){
            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 , "Guest pass: ") ; 
            ret =keypad_get_value_blocking(&keypad1 , &key5) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 13 , key5 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 13 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key6) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 14 , key6 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 14 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key7) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 15 , key7 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 15 , '*') ; 
            ret =keypad_get_value_blocking(&keypad1 , &key8) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , key8 ) ; 
            __delay_ms(200) ; 
            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 16 , '*') ; 
            __delay_ms(300) ; 

            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION4 , &key1) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION5 , &key2) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION6 , &key3) ; 
            ret = Data_EEPROM_ReadByte(EEPROM_LOCATION7 , &key4) ; 
            if((key5 == key1) && (key6 == key2) &&(key7 == key3) &&(key8 == key4)){
                label_8:
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 1, 2 ,"you are an guest ") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1 - Reception") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2 - Back ") ;
                ret = led_turn_on(&led1) ; 
                ret = led_turn_off(&led2) ; 
                ret = led_turn_off(&led3) ; 
                
                
                ret =keypad_get_value_blocking(&keypad1 , &l_value) ; ;
                if(l_value == '1'){
                    label_9 :
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 1, 7 ,"Reception") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Toggle the TV ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- The air COND ") ;
                    ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                    
                    ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                    if(l_value == '1'){
                        MSSP_I2C_SEND_BYTE(slave, 'e');
                        goto label_9 ;  
                    }
                    else if(l_value == '2'){
                        label_12 :
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 1, 3 ,"The air Condition") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Set Temp") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Control ") ;
                        ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                        
                        
                        ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                        if(l_value == '1'){
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"Set Temp :__ C") ;
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 11 ,l_value) ;
                            MSSP_I2C_SEND_BYTE(slave,l_value );
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            ret = lcd_8bit_send_char_data_pos(&lcd1 , 2, 12 ,l_value) ;
                            MSSP_I2C_SEND_BYTE(slave , l_value);
                            __delay_ms(500) ;
                            goto label_10 ;
                            
                        }
                        else if(l_value == '2'){
                            label_13 :
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"1- Close COND") ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 3, 1 ,"2- Open COND") ;
                            ret = lcd_8bit_send_string_pos(&lcd1 , 4, 1 ,"3- Back ") ;
                            ret =keypad_get_value_blocking(&keypad1 , &l_value) ;
                            
                            if(l_value == '1'){
                                MSSP_I2C_SEND_BYTE(slave, 'g');
                                goto label_13 ;  
                            }
                            else if(l_value == '2'){
                                MSSP_I2C_SEND_BYTE(slave, 'h');
                                goto label_13 ;  
                            }
                            else if(l_value == '3'){
                                goto label_12 ;
                            }
                            else{
                                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                                __delay_ms(500) ; 
                                goto label_13 ;
                            }
                        }
                        else if(l_value == '3'){
                            goto label_9 ; 
                        }
                        else{
                            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                            __delay_ms(500) ; 
                            goto label_13 ; 
                        }
                         
                    }
                    else if(l_value == '3'){
                        goto label_8 ;
                    }
                    else{
                        ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                        ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                        __delay_ms(500) ; 
                        goto label_9 ; 
                    }
                }
                else if(l_value == '2'){
                    ret = led_turn_off(&led2) ; 
                    ret = led_turn_off(&led1) ;
                    ret = led_turn_off(&led3) ;
                    goto label_1 ;
                }
                else{
                    ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                    ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
                    __delay_ms(500) ; 
                    goto label_8 ;  
                }
            }
            else if( i < 2){
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ," Please try again ") ;
                __delay_ms(500) ; 

            }
            else if (i == 2){
                ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
                ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"U are in block mode") ;
                ret = lcd_8bit_send_string_pos(&lcd1 , 3, 7 ," Wait ") ;
                ret = led_turn_on(&led3) ; 
                ret = led_turn_off(&led2) ; 
                ret = led_turn_off(&led1) ;
                __delay_ms(2000) ; 
                ret = led_turn_off(&led2) ; 
                ret = led_turn_off(&led1) ;
                ret = led_turn_off(&led3) ;

                i = -1  ; 
                
            }
        }
            
        }
        else{
            ret = lcd_8bit_send_command(&lcd1  , _LCD_CLEAR) ; 
            ret = lcd_8bit_send_string_pos(&lcd1 , 2, 1 ,"It is not an option") ;
            __delay_ms(500) ; 
            goto label_1 ; 
        }

    }

    while(1){

        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize() ; 
    
}
*/ 
 
 
void MSSP_I2C_DefaultInterruptHandler();
void ADC_DefaultInterruptHandler(void);


uint16 adc_res_1 ;  
uint8 slave_ack = 0;
static volatile uint8 i2c_slave1_rec_data;
uint8 temp = 100 , temp2 = 0, flag = 0  , open_flag = 0 ;  



adc_conf_t adc_1 = {
    .ADC_InterruptHandler = ADC_DefaultInterruptHandler,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};

void ADC_DefaultInterruptHandler(void){
    Std_ReturnType ret  = E_NOT_OK;
    ret = ADC_GetConversionResult(&adc_1, &adc_res_1);
    adc_res_1=  (adc_res_1/2) -1 ; 
}


mssp_i2c_t slave_obj = {
    .I2C_DefaultInterruptHandler = MSSP_I2C_DefaultInterruptHandler , 
    .I2C_Report_Receive_Overflow = NULL , 
    .I2C_Report_Write_Collision = NULL ,  
    .i2c_cfg.i2c_slave_address = 0x60 ,
    .i2c_clock = 100000,
    .i2c_cfg.i2c_general_call = I2C_GENERAL_CALL_DISABLE , 
    .i2c_cfg.i2c_mode = I2C_MSSP_SLAVE_MODE , 
    .i2c_cfg.i2c_mode_cfg = I2C_SLAVE_MODE_7BIT_ADDRESS , 
    .i2c_cfg.i2c_SMBus_control = I2C_SMBus_DISABLE , 
    .i2c_cfg.i2c_slew_rate = I2C_SLEW_RATE_DISABLE , 
} ;

void MSSP_I2C_DefaultInterruptHandler(void) {
    // Holds clock low (clock stretch) 
    I2C_CLOCK_STRETCH_ENABLE();
    if ((SSPSTATbits.R_nW == 0) && (SSPSTATbits.D_nA == 0)) { // Master Will Write Data, So i need to read it 
        uint8 dummy_buffer = SSPBUF; // Read The Last Byte To Clear The Buffer 
        while (!SSPSTATbits.BF);
        i2c_slave1_rec_data = SSPBUF; // read data 
    } else if (SSPSTATbits.R_nW == 1) { // Master needs to read Data, So i need to write it 

    } else {
        // Nothing 
    }
    // Releases clock 
    I2C_CLOCK_STRETCH_DISABLE();
}




int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    ret = MSSP_I2C_Init(&slave_obj) ; 
    
    while(1){
        if ('a' == i2c_slave1_rec_data) {
            ret = led_turn_toggle(&room_1);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('b' == i2c_slave1_rec_data){
            ret = led_turn_toggle(&room_2);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('c' == i2c_slave1_rec_data){
            ret = led_turn_toggle(&room_3);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('d' == i2c_slave1_rec_data){
            ret = led_turn_toggle(&room_4);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('e' == i2c_slave1_rec_data){
            ret = led_turn_toggle(&TV);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('g' == i2c_slave1_rec_data){
            ret = ADC_DeInit(&adc_1) ; 
            open_flag = 0 ; 
            ret = led_turn_off(&COND);
            i2c_slave1_rec_data = 0  ; 
        }
        else if ('h' == i2c_slave1_rec_data){
            ret = ADC_Init(&adc_1) ; 
            open_flag  = 1; 
            i2c_slave1_rec_data = 0  ; 
        }
        else if(('0' == i2c_slave1_rec_data)||('1' == i2c_slave1_rec_data)||('2' == i2c_slave1_rec_data)||('3' == i2c_slave1_rec_data)||('4' == i2c_slave1_rec_data)||('5' == i2c_slave1_rec_data)||('6' == i2c_slave1_rec_data)||('7' == i2c_slave1_rec_data)||('8' == i2c_slave1_rec_data)||('9' == i2c_slave1_rec_data)){
            if( flag == 0){
                 temp2  =  (i2c_slave1_rec_data - '0')*10 ; 
                flag ++ ; 
                
            }
            else if (flag == 1){
                temp  =  temp2 + (i2c_slave1_rec_data - '0') ; 
                flag = 0  ;
            }
            i2c_slave1_rec_data = 0  ; 
        }

        else {
            // NO Thing 
        }
        
        if(open_flag == 1){
        
            ret = ADC_StartConversion_Interrupt(&adc_1, ADC_CHANNEL_AN0);
            if(adc_res_1 > temp){
                ret = led_turn_on(&COND);

            }
            else{
                ret = led_turn_off(&COND);
            }       
        }


    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize() ; 
    
}

 


