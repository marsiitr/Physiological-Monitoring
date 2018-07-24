#include <SoftwareSerial.h>
SoftwareSerial mySerial(5,6);

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  char c = mySerial.read();
  Serial.println(c);
}
