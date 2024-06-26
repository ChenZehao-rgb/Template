#include "bsp_adc.h"

/**********************************************************
 * 函 数 名 称：adc_config
 * 函 数 功 能：ADC初始化
 * 传 入 参 数：无
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：无
**********************************************************/
void adc_config(void)
{
	//使能引脚时钟
    rcu_periph_clock_enable(RCU_GPIOC);      
    //使能ADC时钟
    rcu_periph_clock_enable(RCU_ADC0);
    //配置ADC时钟
    adc_clock_config(ADC_ADCCK_PCLK2_DIV4);
	
	//配置引脚为模拟输入模式
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1); 
	
	//配置ADC为独立模式      
	adc_sync_mode_config(ADC_SYNC_MODE_INDEPENDENT);
		
	//使能扫描模式
	adc_special_function_config(ADC0, ADC_SCAN_MODE, ENABLE);

	//数据右对齐     
	adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
	   
	//ADC0设置为12位分辨率               
	adc_resolution_config(ADC0, ADC_RESOLUTION_12B);
	
	//ADC0设置为规则组  一共使用 1 个通道
	adc_channel_length_config(ADC0,ADC_ROUTINE_CHANNEL, 1);

	//ADC外部触发禁用, 即只能使用软件触发
	adc_external_trigger_config(ADC0, ADC_ROUTINE_CHANNEL, EXTERNAL_TRIGGER_DISABLE);

	//ADC0使能
	adc_enable(ADC0);

	//开启ADC自校准
	adc_calibration_enable(ADC0); 
}

/**********************************************************
 * 函 数 名 称：Get_ADC_Value
 * 函 数 功 能：读取ADC值
 * 传 入 参 数：ADC_CHANNEL_x=要采集的通道
 * 函 数 返 回：测量到的值
 * 作       者：LC
 * 备       注：无
**********************************************************/
unsigned int Get_ADC_Value(uint8_t  ADC_CHANNEL_x)
{
    unsigned int adc_value = 0;
    //设置采集通道
    adc_routine_channel_config(ADC0, 0, ADC_CHANNEL_x, ADC_SAMPLETIME_15);
    //开始软件转换
    adc_software_trigger_enable(ADC0, ADC_ROUTINE_CHANNEL);
    //等待 ADC0 采样完成 
    while ( adc_flag_get(ADC0, ADC_FLAG_EOC) == RESET ) 
    {
        ;
    }
    //读取采样值
    adc_value = adc_routine_data_read(ADC0);
    //返回采样值
    return adc_value;
}
