int inputpin = A0;
int inputvalue = 0;

void setup() 
{ pinMode (2,OUTPUT);
Serial.begin(9600);

}

void loop() 
{ inputvalue = analogRead(inputpin);
Serial.println(inputvalue);

if(inputvalue < 800)
digitalWrite(2,HIGH);
else 
digitalWrite(2,LOW);
}
