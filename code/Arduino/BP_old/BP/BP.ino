#include<SoftwareSerial.h>
SoftwareSerial BP(5, 6); // RX,TX

void setup() {
  Serial.begin(9600);
  BP.begin(9600);
}

void loop() {
//  if(BP.available())
//  {
//        BTserial.println(BP.read());
    Serial.write(BP.read());
//  }
}
