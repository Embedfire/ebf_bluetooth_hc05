/**
  ******************************************************************************
  * @file    bsp_SysTick.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   SysTick 系统滴答时钟10us中断函数库,中断时间可自由配置，
  *          常用的有 1us 10us 1ms 中断。     
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F429 开发板
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./systick/bsp_SysTick.h"

static __IO uint32_t TimingDelay=0;
__IO uint32_t g_ul_ms_ticks=0;
 
/**
  * @brief  启动系统滴答定时器 SysTick
  * @param  无
  * @retval 无
  */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
	if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		/* Capture error */ 
		while (1);
	}
}

void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
		TimingDelay--;
}

void mdelay(unsigned long nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}


int get_tick_count(unsigned long *count)
{
        count[0] = g_ul_ms_ticks;
	return 0;
}



void TimeStamp_Increment(void)
{
	g_ul_ms_ticks++;
}

/*********************************************END OF FILE**********************/
