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
#include <PubSubClient.h>
#include <mqtt_client.h>

#include "app_config.h"
#include "serialize.h"

namespace mqtt_client {

const char* k_client_name = _MQTT_CLIENT_NAME;
const char* k_subscribed_topics_names[] = _MQTT_SUBSCRIBED_TOPICS_NAMES;
const std::function<void(byte*, uint)> k_subscribed_topics_callbacks[] = _MQTT_SUBSCRIBED_TOPICS_CALLBACKS;
uint k_num_topics;
const char* k_broker_ip = _MQTT_BROKER_IP;
const uint k_broker_port = _MQTT_BROKER_PORT;

WiFiClient k_esp_client;
PubSubClient k_client(k_esp_client);

void
setup()
{
  k_client.setServer(k_broker_ip, k_broker_port);
  k_client.setCallback(callback);
  k_num_topics = sizeof(k_subscribed_topics_names) / sizeof(*k_subscribed_topics_names);
}

void
callback(String topic, byte* message, uint length)
{
#ifdef _CONSOLE_DEBUG
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
#endif
  for(auto i = 0u; i < k_num_topics; i++)
  {
    if(topic == k_subscribed_topics_names[i])
    {
      k_subscribed_topics_callbacks[i](message, length);
    }
  }
}

void
connect()
{
  while(!k_client.connected())
  {
#ifdef _CONSOLE_DEBUG
    Serial.print("Attempting MQTT connection...");
#endif
    // Attempt to connect
    if(k_client.connect(k_client_name))
    {
#ifdef _CONSOLE_DEBUG
      Serial.println("Connected");
#endif
      // Subscribe or resubscribe to topics
      for(auto i = 0u; i < k_num_topics; i++)
      {
        k_client.subscribe(k_subscribed_topics_names[i]);
      }
    }
    else
    {

#ifdef _CONSOLE_DEBUG
      Serial.print("Failed, rc=");
      Serial.print(k_client.state());
      Serial.println(" try again in 3 seconds");
#endif
      delay(3000);
    }
  }
}

bool
isConnected()
{
  return k_client.connected();
}

bool
loop()
{
  return k_client.loop();
}


void
publish(const char* topic, const char* message)
{
  k_client.publish(topic,message);
}
}  // namespace mqtt_client