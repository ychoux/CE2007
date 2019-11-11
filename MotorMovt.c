void MotorMovt(void){
    static uint32_t count=0;
    static uint8_t motor_state=0;
    //Write this as part of lab3 Bonus Challenge

    if(CollisionFlag == 1){
        // hit->rev->turn right 180
        if(CollisionData == 51){
           Motor_Backward(3000,3000);
           Clock_Delay1ms(1000);
           Motor_Right(3000,3000);
           Clock_Delay1ms(1400);
        }
        else if((CollisionData<=55  && CollisionData>=7)){
            if(CollisionData == 31){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Right(3000,3000);
                Clock_Delay1ms(250);
            }
            else if(CollisionData == 47){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Right(3000,3000);
                Clock_Delay1ms(400);
            }
            else if(CollisionData == 55){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Right(3000,3000);
                Clock_Delay1ms(700);
            }
            else{
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Right(3000,3000);
                Clock_Delay1ms(700);
            }
        }
        // hit->rev->turn left 90 (hit right bumps)
        else if((CollisionData<=62  && CollisionData>=56 )){
            if(CollisionData == 62){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Left(3000,3000);
                Clock_Delay1ms(250);
            }
            else if (CollisionData == 61){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Left(3000,3000);
                Clock_Delay1ms(400);
            }
            else if(CollisionData == 59){
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Left(3000,3000);
                Clock_Delay1ms(700);
            }else{
                Motor_Backward(3000,3000);
                Clock_Delay1ms(1000);
                Motor_Left(3000,3000);
                Clock_Delay1ms(700);
            }
        }
        CollisionFlag = 0;
    }

    Motor_Forward(3000,3000);
}
