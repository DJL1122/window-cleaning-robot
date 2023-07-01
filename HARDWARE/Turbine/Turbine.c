#include "Turbine.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB7和PE8为输出口.并使能这两个口的时钟		    
//LED IO初始化
void Turbine_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;				 //GPIO-->PB.7 PB.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB
	
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_7|GPIO_Pin_8);						 //PB.7 PB.8 输出高

}

void Turbine_1_STOP(void)
{
	TN1(High);
	TN2(High);
}
 
void Turbine_1_Start(void)
{
	TN1(Low);
	TN2(High);
}
 
