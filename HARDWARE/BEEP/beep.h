#ifndef _BEEP_H_
#define _BEEP_H_

//typedef enum 
//{
//	OFF = 0, 
//	ON = !OFF
//}BEEPState;

//#define BEEP(EN)		(EN) ? (GPIO_SetBits(GPIOB, GPIO_Pin_3)) : (GPIO_ResetBits(GPIOB, GPIO_Pin_3))
void BEEP_IO_Configration(void);
void BEEP(int S);
	
#endif
