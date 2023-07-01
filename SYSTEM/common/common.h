#ifndef __COMMON_H__
#define __COMMON_H__	 
#include "sys.h"
#include "usart.h"		
#include "delay.h"	 	 	 	 	 
#include "string.h"


//结构体变量如果想作为全局变量使用的话，需要在头文件中声明。
struct stuSystemStatus{
	int bLightOpen;
    int bDoorSwitch;
	int bWindowCurtainsOpen;
    float fLightIntensity;
};	

extern struct stuSystemStatus mSysStatus;

#endif





