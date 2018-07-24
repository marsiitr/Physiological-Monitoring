#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#include <SoftwareSerial.h>
OneWire oneWire(ONE_WIRE_BUS);
SoftwareSerial BTserial(10, 11); 
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
   BTserial.begin(9600);
 // BTserial.begin(9600);
 sensors.begin();
}

void loop(void)
{
  BTserial.println("Temperature of body (in Celsius):");
  sensors.requestTemperatures();
  BTserial.println(sensors.getTempCByIndex(0));
  delay(1000);
}

