#include "Turbine.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB7��PE8Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void Turbine_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;				 //GPIO-->PB.7 PB.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB
	
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_7|GPIO_Pin_8);						 //PB.7 PB.8 �����

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
 
