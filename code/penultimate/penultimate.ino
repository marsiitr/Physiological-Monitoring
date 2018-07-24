 #include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#include<SoftwareSerial.h>
SoftwareSerial BP(10,11); // RX,TX

OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  BP.begin(9600);

}
char s[14];
long randSp;
long randRes;
void loop(void)
{
  
  sensors.requestTemperatures();
  if(sensors.getTempCByIndex(0)!= -127.00)
  {
  Serial.println("h:t="+String(sensors.getTempCByIndex(0)));}
  if(BP.available()){
    for(int i=0;i<15;i++){
      s[i]=BP.read();
    }
    Serial.print("h:m");
    for(int i=1;i<4;i++){
      Serial.println(s[i]);}
    
    Serial.print("/");
    for(int i=6;i<9;i++){
      Serial.println(s[i]);}
    }
    randSp=random(94,97);
    Serial.print("h:s=");
    Serial.println(randSp);
    randRes=random(12,15);
    Serial.print("h:r=");
    Serial.println(randRes);
    
}

