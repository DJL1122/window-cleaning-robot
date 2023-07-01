#include "motor.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void motor_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;				 //GPIO-->PB.5 PB.6 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
	
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6);						 //PB.5 输出高
	

}

void Motor_1_STOP(void)
{
	IN1(High);
	IN2(High);
}
 
void Motor_1_DRun(void)
{
	IN1(Low);
	IN2(High);
}
 
void Motor_1_RRun(void)
{
	IN1(High);
	IN2(Low);
}
 
