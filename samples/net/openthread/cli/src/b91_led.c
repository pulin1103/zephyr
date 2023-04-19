#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include "b91_led.h"

#define REG_RW_BASE_ADDR  			0x80000000
#define REG_ADDR8(a)				(*(volatile unsigned char*)(REG_RW_BASE_ADDR | (a)))
#define reg_gpio_out(i)				REG_ADDR8(0x140303+((i>>8)<<3))

typedef enum{
		GPIO_GROUPA    = 0x000,
		GPIO_GROUPB    = 0x100,
		GPIO_GROUPC    = 0x200,
		GPIO_GROUPD    = 0x300,
		GPIO_GROUPE    = 0x400,
		GPIO_GROUPF    = 0x500,
		GPIO_ALL       = 0x600,
	    GPIO_PA0 = GPIO_GROUPA | BIT(0),
		GPIO_PA1 = GPIO_GROUPA | BIT(1),
		GPIO_PA2 = GPIO_GROUPA | BIT(2),
		GPIO_PA3 = GPIO_GROUPA | BIT(3),
		GPIO_PA4 = GPIO_GROUPA | BIT(4),
		GPIO_PA5 = GPIO_GROUPA | BIT(5),GPIO_DM=GPIO_PA5,
		GPIO_PA6 = GPIO_GROUPA | BIT(6),GPIO_DP=GPIO_PA6,
		GPIO_PA7 = GPIO_GROUPA | BIT(7),GPIO_SWS=GPIO_PA7,
		GPIOA_ALL = GPIO_GROUPA | 0x00ff,

		GPIO_PB0 = GPIO_GROUPB | BIT(0),
		GPIO_PB1 = GPIO_GROUPB | BIT(1),
		GPIO_PB2 = GPIO_GROUPB | BIT(2),
		GPIO_PB3 = GPIO_GROUPB | BIT(3),
		GPIO_PB4 = GPIO_GROUPB | BIT(4),
		GPIO_PB5 = GPIO_GROUPB | BIT(5),
		GPIO_PB6 = GPIO_GROUPB | BIT(6),
		GPIO_PB7 = GPIO_GROUPB | BIT(7),

		GPIO_PC0 = GPIO_GROUPC | BIT(0),GPIO_SWM=GPIO_PC0,
		GPIO_PC1 = GPIO_GROUPC | BIT(1),
		GPIO_PC2 = GPIO_GROUPC | BIT(2),
		GPIO_PC3 = GPIO_GROUPC | BIT(3),
		GPIO_PC4 = GPIO_GROUPC | BIT(4),
		GPIO_PC5 = GPIO_GROUPC | BIT(5),
		GPIO_PC6 = GPIO_GROUPC | BIT(6),
		GPIO_PC7 = GPIO_GROUPC | BIT(7),
		GPIOC_ALL = GPIO_GROUPC | 0x00ff,

		GPIO_PD0 = GPIO_GROUPD | BIT(0),
		GPIO_PD1 = GPIO_GROUPD | BIT(1),
		GPIO_PD2 = GPIO_GROUPD | BIT(2),
		GPIO_PD3 = GPIO_GROUPD | BIT(3),
		GPIO_PD4 = GPIO_GROUPD | BIT(4),
		GPIO_PD5 = GPIO_GROUPD | BIT(5),
		GPIO_PD6 = GPIO_GROUPD | BIT(6),
		GPIO_PD7 = GPIO_GROUPD | BIT(7),

		GPIO_PE0 = GPIO_GROUPE | BIT(0),
		GPIO_PE1 = GPIO_GROUPE | BIT(1),
		GPIO_PE2 = GPIO_GROUPE | BIT(2),
		GPIO_PE3 = GPIO_GROUPE | BIT(3),
		GPIO_PE4 = GPIO_GROUPE | BIT(4),
		GPIO_PE5 = GPIO_GROUPE | BIT(5),
		GPIO_PE6 = GPIO_GROUPE | BIT(6),
		GPIO_PE7 = GPIO_GROUPE | BIT(7),
		GPIOE_ALL = GPIO_GROUPE | 0x00ff,

		GPIO_PF0 = GPIO_GROUPF | BIT(0),
		GPIO_PF1 = GPIO_GROUPF | BIT(1),
		GPIO_PF2 = GPIO_GROUPF | BIT(2),
		GPIO_PF3 = GPIO_GROUPF | BIT(3),

}gpio_pin_e;

int LED_Init(void)
{
	int ret = 0;

	ret = gpio_pin_configure(LED_PORT_B, LED_PIN_6, GPIO_OUTPUT);
	if(ret < 0)
	{
		printk("Config in pin err: %d", ret);
		return ret;
	}

	ret = gpio_pin_set(LED_PORT_B, LED_PIN_6, 1);
	if(ret < 0)
	{
		printk("Set default value in pin err: %d", ret);
		return ret;
	}
	return ret;
}
/*
int LED_Toggle(void)
{
	int ret = 0;
	ret = gpio_pin_toggle(LED_PORT_B, LED_PIN_6);
	if(ret < 0)
	{
		printk("Toggle led fail!");
		return ret;
	}
	return ret;
}
*/

static inline void gpio_toggle(gpio_pin_e pin)
{
	reg_gpio_out(pin) ^= (pin & 0xFF);
}

void inline LED_Toggle(void)
{
	gpio_toggle(GPIO_PB6);
}

