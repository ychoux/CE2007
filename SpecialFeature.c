volatile uint32_t block=0;
void Special_Feature(){
    uint32_t raw17,raw12,raw16;
    int32_t n; uint32_t s;
    ADC0_InitSWTriggerCh17_12_16();   // initialize channels 17,12,16
    ADC_In17_12_16(&raw17,&raw12,&raw16);  // sample
    LPF_Init(raw17,s);     // P9.0/channel 17
    LPF_Init2(raw12,s);    // P4.1/channel 12
    LPF_Init3(raw16,s);
    UART0_Init();          // initialize UART0 115,200 baud rate
    LaunchPad_Init();
    EnableInterrupts();
    TimedPause(50);
    while(1){
        TimerA1_Init(&SensorRead_ISR,250);
        for(n=0; n<2000; n++){
           while(ADCflag == 0){};
           ADCflag = 0; // show every 2000th point
        }
        UART0_OutString("Left:");UART0_OutUDec5(LeftConvert(nl));UART0_OutString(" mm "); //Debugging
        UART0_OutString("Center:");UART0_OutUDec5(CenterConvert(nc));UART0_OutString(" mm "); //Debugging
        UART0_OutString("Right:");UART0_OutUDec5(RightConvert(nr));UART0_OutString(" mm \n"); //Debugging

        //Block 0 = free of obstacle
        //Block 1 = obstacle in front
        if(CollisionFlag == 1){
            TimerA1_Init(&MotorMovt,50000);  // 10 Hz
            WaitForInterrupt();
            Motor_Forward(2000,2000);
        }

        if(block == 0){
            if(CenterConvert(nc)>=40 && CenterConvert(nc)<=200){ //Incoming obstacle
                block = 1;
            }
            else{
                TimerA1_Init(&Task, 50000);
                Motor_Init();
                Motor_Forward(2000,2000);
            }
        }
        else{ //Check for clear path
            if(RightConvert(nr)>=60 && CenterConvert(nc)>=100 && LeftConvert(nl)>=100){
                block = 0;
            }
            else{
                TimerA1_Init(&Task, 50000);
                Motor_Init();
                Motor_Left(1000,1000);
            }
        }

    }

}
