#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define LED_PORT_B DEVICE_DT_GET(DT_NODELABEL(gpiob))
#define LED_PIN_6 6

int LED_Init();
void LED_Toggle();

#ifdef __cplusplus
}
#endif