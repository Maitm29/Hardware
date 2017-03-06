#include <Event.h>
#include <Timer.h>

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
int ledpin = 5;
int ldrpin = A1;
int value = 0;
int const trigPin = 13;
int const echoPin = 6;
int duration ;int distance;
Timer t;
int pin =13;
void glowled();
void shutled();


void shutled()
{analogWrite(ledpin,LOW);
  }

void glowled()
{
value = analogRead(ldrpin);
  value = constrain(value,900,1010);
  value = map(value,900,1010,255,0);

 


  analogWrite(ledpin, value); 
  }

void setup() {

  Serial.begin(9600);
  Wire.begin();

  rtc.begin();

  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running!");
  }
  //Any pin. I have used Pin 4
  pinMode(4, OUTPUT);
t.pulse(pin,1000,HIGH); 
t.every(10*60*1000,glowled);
}

void loop() {
   void glowled();
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.println();
    delay(1000);

      //The time is set as 24 hours
     //Pin 4 get high at 6pm and low at 6am
    if (now.hour() == 18 & now.minute() == 0 & now.second() == 0)
    {
     digitalWrite(4,HIGH);
    }

    else if (now.hour() == 6 & now.minute() == 0 & now.second() == 0)
    {
      digitalWrite(4,LOW);
    }
 if (now.hour() ==2252 & now.minute() ==02 & now.second () == 0)
 {// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
  void shutled();
  if (distance <= 50 && distance >= 0)
  {
  t.update();
 }
 }
 else
 void shutled();
}

