/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  char incomingByte;
  static int delayms = 100;
  static int delaymsoff = 1000;

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  // wait for a second
  delay(delayms);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
   // wait for a second
  delay(delaymsoff);

  if(Serial.available()>0)
  {
    incomingByte = Serial.read();

    Serial.print("IN:");
    Serial.println(incomingByte);

    if(incomingByte == '+'){
      Serial.println("going up");
      delaymsoff += 100;
    }
    if(incomingByte == '-'){
      Serial.println("going down");
      delaymsoff -= 100;
    }    
    Serial.println(delaymsoff);
  }
}
