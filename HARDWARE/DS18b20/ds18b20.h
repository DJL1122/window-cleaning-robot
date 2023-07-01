#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   

//IO????
#define DS18B20_IO_IN()  {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=8<<12;}
#define DS18B20_IO_OUT() {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=3<<12;}
							   
#define	DS18B20_DQ_OUT PAout(11) //????	PA0 
#define	DS18B20_DQ_IN  PAin(11)  //????	PA0 
   	
u8 DS18B20_Init(void);//???DS18B20
short DS18B20_Get_Temp(void);//????
void DS18B20_Start(void);//??????
void DS18B20_Write_Byte(u8 dat);//??????
u8 DS18B20_Read_Byte(void);//??????
u8 DS18B20_Read_Bit(void);//?????
u8 DS18B20_Check(void);//??????DS18B20
void DS18B20_Rst(void);//??DS18B20    
#endif

