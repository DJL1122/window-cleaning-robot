/**
	************************************************************
	************************************************************
	************************************************************
	*	�ļ����� 	led.c
	*
	*	���ߣ� 		�ż���
	*
	*	���ڣ� 		2016-11-23
	*
	*	�汾�� 		V1.0
	*
	*	˵���� 		BEEP��ʼ��������
	*
	*	�޸ļ�¼��	
	************************************************************
	************************************************************
	************************************************************
**/

//��Ƭ��ͷ�ļ�
#include "stm32f10x.h"

//Ӳ������
#include "beep.h"




/*????????*/ 
void BEEP_IO_Configration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
		
	/*?? APB2 - PE ????*/ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	   

	/*PE12????*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	  			// ?? PE12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		// ????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// IO????50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);	 

  GPIO_SetBits(GPIOB, GPIO_Pin_3);					// PE12 gao

  //GPIO_ResetBits(GPIOB, GPIO_Pin_3);					// PE12 ?????

	
}

void BEEP(int S)
{
	if(S==1){
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);	
	}
	else{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);
	}
}

