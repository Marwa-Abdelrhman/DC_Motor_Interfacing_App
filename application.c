/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"





Std_RetrunType ret=E_NOK;
dc_motor_t motor1={.dc_motor_pin[0].port=PORTC_INDEX,
                   .dc_motor_pin[0].pin=GPIO_PIN0,
                   .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[0].state=DC_MOTOR_OFF_STATE,
                   .dc_motor_pin[1].port=PORTC_INDEX,
                   .dc_motor_pin[1].pin=GPIO_PIN1,
                   .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[1].state=DC_MOTOR_OFF_STATE};


dc_motor_t motor2={.dc_motor_pin[0].port=PORTC_INDEX,
                   .dc_motor_pin[0].pin=GPIO_PIN2,         
                   .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[0].state=DC_MOTOR_OFF_STATE,
                   .dc_motor_pin[1].port=PORTC_INDEX,
                   .dc_motor_pin[1].pin=GPIO_PIN3,
                   .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[1].state=DC_MOTOR_OFF_STATE};





int main() {
    app_init();
    while(1){
        
        
         ret=dc_motor_move_right(&motor1);
         ret=dc_motor_move_right(&motor2);
        __delay_ms(3000);
       
         ret=dc_motor_move_left(&motor1);
         ret=dc_motor_move_left(&motor2);
        __delay_ms(3000);
        
         ret=dc_motor_move_right(&motor1);
         ret=dc_motor_move_left(&motor2);
        __delay_ms(3000);
        
         ret=dc_motor_move_right(&motor2);
         ret=dc_motor_move_left(&motor1);
        __delay_ms(3000);
        
         ret=dc_motor_stop(&motor1);
         ret=dc_motor_stop(&motor2);
        __delay_ms(3000);
        


    }
        return (EXIT_SUCCESS);
}

void app_init(void){
  
    ret=dc_motor_init(&motor1);
    ret=dc_motor_init(&motor2);

    
}