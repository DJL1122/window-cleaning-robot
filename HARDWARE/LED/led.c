#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//LED点灯代码							  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB4为输出口.并使能这个口的时钟		    
//LED I1初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PA端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 //LED0-->PB.4 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB
 GPIO_SetBits(GPIOB,GPIO_Pin_4);						 //PB.4 输出低
	

}
 
void led1_on(void)
{			
	GPIO_ResetBits(GPIOB,GPIO_Pin_4);			    //PB4 输出高
} 

void led1_off(void)
{			
	GPIO_SetBits(GPIOB,GPIO_Pin_4);		    //PB4 输出低
} 