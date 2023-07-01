#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"


#define High    1
#define Low     0
 
#define IN1(a) if (a)  \
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);\
else  \
	GPIO_SetBits(GPIOB,GPIO_Pin_5)
 
#define IN2(a) if (a)  \
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);\
else  \
	GPIO_SetBits(GPIOB,GPIO_Pin_6)


void motor_Init(void);

void Motor_1_STOP(void);
void Motor_1_DRun(void);
void Motor_1_RRun(void);

		 				    
#endif
