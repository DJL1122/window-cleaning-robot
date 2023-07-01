#ifndef __Turbine_H
#define __Turbine_H	 
#include "sys.h"


#define High    1
#define Low     0
 
#define TN1(a) if (a)  \
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);\
else  \
	GPIO_SetBits(GPIOB,GPIO_Pin_7)
 
#define TN2(a) if (a)  \
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);\
else  \
	GPIO_SetBits(GPIOB,GPIO_Pin_8)


void Turbine_Init(void);
void Turbine_1_STOP(void);
void Turbine_1_Start(void);	
#endif
