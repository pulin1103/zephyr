/* main.c - OpenThread CLI */

/*
 * Copyright (c) 2020 Tridonic GmbH & Co KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/logging/log.h>
#include "b91_led.h"
LOG_MODULE_REGISTER(ot_cli, LOG_LEVEL_DBG);

#define APP_BANNER "***** OpenThread CLI on Zephyr %s *****"

void main(void)
{
	LED_Init();
	LOG_INF(APP_BANNER, CONFIG_NET_SAMPLE_APPLICATION_VERSION);
	LED_Toggle();
}