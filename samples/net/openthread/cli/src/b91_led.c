#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include "b91_led.h"


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

