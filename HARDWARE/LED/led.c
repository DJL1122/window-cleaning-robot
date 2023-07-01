#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//LED��ƴ���							  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB4Ϊ�����.��ʹ������ڵ�ʱ��		    
//LED I1��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PB,PA�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 //LED0-->PB.4 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB
 GPIO_SetBits(GPIOB,GPIO_Pin_4);						 //PB.4 �����
	

}
 
void led1_on(void)
{			
	GPIO_ResetBits(GPIOB,GPIO_Pin_4);			    //PB4 �����
} 

void led1_off(void)
{			
	GPIO_SetBits(GPIOB,GPIO_Pin_4);		    //PB4 �����
} 