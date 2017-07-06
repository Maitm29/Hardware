// pin 4,6 fron rf-rx d0,d1
// pin 13 to relay IN1

int  sensorPin_on = 4;
int sensorPin_off = 6;
int outpin = 13; 
 void setup()
 {
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(4,INPUT);
  pinMode(13,OUTPUT); 
 }

void loop()
{
  int pulse_on,pulse_off;
  pulse_on = digitalRead(sensorPin_on);
  pulse_off = digitalRead(sensorPin_off);
  if(pulse_on == LOW)
  {
    digitalWrite(outpin,HIGH);
    delay(2000);
  }
  if(pulse_off == LOW)
  {
    digitalWrite(outpin,LOW);
    delay(2000);  
  }
}
