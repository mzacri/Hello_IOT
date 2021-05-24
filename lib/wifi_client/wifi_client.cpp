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

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <wifi_client.h>
#include "app_config.h"

namespace wifi_client {

const char* k_ssid = _WIFI_SSID;
const char* k_password = _WIFI_PASSWORD;

void
setup()
{
  delay(10);
#ifdef _CONSOLE_DEBUG
  Serial.print("Connecting to ");
  Serial.println(k_ssid);
#endif
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(k_ssid, k_password);
  }
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
#ifdef _CONSOLE_DEBUG
    Serial.print(".");
#endif
  }
#ifdef _CONSOLE_DEBUG 
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
  return;
#endif
}
}  // namespace wifi_client