/**
	************************************************************
	************************************************************
	************************************************************
	*	文件名： 	led.c
	*
	*	作者： 		张继瑞
	*
	*	日期： 		2016-11-23
	*
	*	版本： 		V1.0
	*
	*	说明： 		BEEP初始化、控制
	*
	*	修改记录：	
	************************************************************
	************************************************************
	************************************************************
**/

//单片机头文件
#include "stm32f10x.h"

//硬件驱动
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

