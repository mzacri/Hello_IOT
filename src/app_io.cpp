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

#include "app_io.h"
#include "app_config.h"

bool detected = false;
namespace app_io {
void
setup()
{
  pinMode(_BUZZER_PIN, OUTPUT);
  pinMode(_PIR_PIN, INPUT);
#ifdef _CONSOLE_DEBUG
  Serial.println("Calibrating PIR sensor, stay still for 15 seconds...");
#endif
  delay(15000);
}

bool
pirDetect(String& detection)
{
  bool edge = true;
  if(digitalRead(_PIR_PIN) and not detected)
  {
    detected = true;
    detection = "Detected";
  }
  else if(not digitalRead(_PIR_PIN) and detected)
  {
    detected = false;
    detection = "Not detected";
  }
  else
  {
    edge = false;
  }
  return edge;
}

void
toggleBuzzer()
{
  tone(_BUZZER_PIN, _BUZZER_FREQUENCY_HZ, _BUZZER_DURATION_MS);
}

}  // namespace app_io