#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "start_task.h"
#include "bsp_led.h"
#include "delay.h"
#include "bsp_can.h"
#include "bsp_usart.h"
#include "bsp_ina226.h"
RCC_ClocksTypeDef RCC_Clocks;//����ʱ��
int main()
{
	RCC_GetClocksFreq(&RCC_Clocks);
	delay_init();
	mx_led_init();
	mx_can_init();
	mx_uart_init();
	mx_iic_init();
	mx_ina226_init();
	create_start_task();	//������ʼ����            
    vTaskStartScheduler();  //�����������
	while(1){}
}
