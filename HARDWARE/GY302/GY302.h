#ifndef __GY302_H
#define __GY302_H
//#include "myiic.h"  

#include "sys.h"

//IIC总线地址接口定义
#define IIC_SCL PBout(8)
#define IIC_SDA_OUT PBout(9)
#define IIC_SDA_IN PBin(9)
 
#define IIC_INPUT_MODE_SET()  {GPIOB->CRH&=0xFFFFFF0F;GPIOB->CRH|=0x00000080;}
#define IIC_OUTPUT_MODE_SET() {GPIOB->CRH&=0xFFFFFF0F;GPIOB->CRH|=0x00000030;}
 
#define  IIC_WRITE      0     // 写
#define  IIC_READ       1     // 读
#define	 SlaveAddress   0x46  //BH1750地址
extern u8  BUF[3];
//函数声明
void IIC_Init(void);
void BH1750_Start(void);
void BH1750_Stop(void);
void BH1750_SendACK(char ack);
char BH1750_RecvACK(void);
void BH1750_SendByte(u8 data);
void Single_Write_BH1750(u8 REG_Address);
void Multiple_Read_BH1750(void);
float Get_Sunlight_Value(void);
u8 BH1750_RecvByte(void);


#endif
















