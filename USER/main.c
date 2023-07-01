#include "led.h"
#include "delay.h"
#include "sys.h"
#include "Turbine.h"
#include "motor.h"
#include "remote.h"
#include "timer.h"

 int main(void)
 {	
	 
	u8 key; 
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE ); //配置复用时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE); //全功能SW+JTAG，禁用JTRST，PB4可用
	LED_Init();	//初始化与LED连接的硬件接口
	Turbine_Init(); //初始化与涡轮连接的硬件连接
	motor_Init(); //初始化与轮子连接的硬件接口
	 
	Turbine_1_STOP(); //初始化设置涡轮静止
	Motor_1_STOP(); //初始化设置轮子静止
	Remote_Init();			//红外接收初始化

	while(1)
	{
        key=Remote_Scan(); //信号接收
        switch(key)
        {

            // led1_on(); 是点亮板载的led灯
            // led1_off(); 是关闭板载的led灯
            // 前进后退左右都是关闭板载的led灯，中间的ok键是点亮板载的led灯
					
            // 执行 前进
						case 24: {
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // 执行 后退
            case 74: {
							led1_on();
							//Motor_1_RRun();
							break;
						}
						
            // 执行 左转
            case 16: {
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // 执行 右转
            case 90:{
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // 执行 停止 OK 
            case 56:{
							led1_off();
							//Motor_1_DRun();
							break;
						}
						
						// 执行 涡轮 打开
						case 152: {
							led1_off();
							//Turbine_1_Start();
							break;
						}
						
						// 执行 涡轮 关闭
						case 176: {
							led1_off();
							//Turbine_1_STOP();
							break;
						}
 			    
						default:break;		 
		}

	}
}

