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
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE ); //���ø���ʱ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE); //ȫ����SW+JTAG������JTRST��PB4����
	LED_Init();	//��ʼ����LED���ӵ�Ӳ���ӿ�
	Turbine_Init(); //��ʼ�����������ӵ�Ӳ������
	motor_Init(); //��ʼ�����������ӵ�Ӳ���ӿ�
	 
	Turbine_1_STOP(); //��ʼ���������־�ֹ
	Motor_1_STOP(); //��ʼ���������Ӿ�ֹ
	Remote_Init();			//������ճ�ʼ��

	while(1)
	{
        key=Remote_Scan(); //�źŽ���
        switch(key)
        {

            // led1_on(); �ǵ������ص�led��
            // led1_off(); �ǹرհ��ص�led��
            // ǰ���������Ҷ��ǹرհ��ص�led�ƣ��м��ok���ǵ������ص�led��
					
            // ִ�� ǰ��
						case 24: {
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // ִ�� ����
            case 74: {
							led1_on();
							//Motor_1_RRun();
							break;
						}
						
            // ִ�� ��ת
            case 16: {
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // ִ�� ��ת
            case 90:{
							led1_on();
							//Motor_1_DRun();
							break;
						}
						
            // ִ�� ֹͣ OK 
            case 56:{
							led1_off();
							//Motor_1_DRun();
							break;
						}
						
						// ִ�� ���� ��
						case 152: {
							led1_off();
							//Turbine_1_Start();
							break;
						}
						
						// ִ�� ���� �ر�
						case 176: {
							led1_off();
							//Turbine_1_STOP();
							break;
						}
 			    
						default:break;		 
		}

	}
}

