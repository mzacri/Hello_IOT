/**
 * 
Copyright (c) 2021 M'barek ZACRI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

#include <Arduino.h>
/**
 * @brief: Debug config
 */
#define _CONSOLE_DEBUG

/**
 * @brief: Wifi client parameters
 */
#define _WIFI_SSID "EL RAPIDO"
#define _WIFI_PASSWORD "E333DD6CAE"

/**
 * @brief: MQTT client parameters
 */
#define _MQTT_CLIENT_NAME "ESPClient"
#define _MQTT_BROKER_IP "192.168.0.118"
#define _MQTT_BROKER_PORT 1883

#define _MQTT_SUBSCRIBED_TOPICS_NAMES \
  {                                   \
    "esp1/buzzer"                      \
  }
#define _MQTT_SUBSCRIBED_TOPICS_CALLBACKS \
  {                                       \
    esp1_buzzer_callback                   \
  }

void
esp1_buzzer_callback(byte* message, uint length);

#define _MQTT_PUBLISH_TOPIC "esp1/pir_detection"

/**
 * @brief: Application IO parameters
 */
#define _PIR_PIN 0

#define _BUZZER_PIN 4
#define _BUZZER_FREQUENCY_HZ 1000 
#define _BUZZER_DURATION_MS 1000