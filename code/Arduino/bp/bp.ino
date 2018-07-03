#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
//int on = 4;

void setup() 
{Serial.begin(9600);
//pinMode(on,OUTPUT);
mySerial.begin(9600);}

char s,c;
void loop() 
{
 c = Serial.read();
 
 if(c == 'o')
 {//pinMode(on,OUTPUT);
 //digitalWrite(on,LOW);
 delay(700);
 //digitalWrite(on,HIGH);
// delay(700);
 //digitalWrite(on,LOW);//why?
// pinMode(on,INPUT);}
 
 s = mySerial.read();
// if (s >= 10 and s<= 60)//why?
 Serial.write(s);
 }}
