# Physiological-Monitoring
Our project “physiological monitor” helps to monitor some persons health conditions from a distant place. Our  project  currently  give  measure of heart  rate,  respiration rate ,blood pressure, body temperature and oxygen saturation in blood.

## Team Members
1. Abhishek
2. Manunjay Mahaur
3. Piyush Bindal 
4. Rakesh Kumar
5. Rajarshi Narvariya	
6. Sundeep sharan

## Mentors
1. Anirudh Garg	
2. Bhaskar Kaushik
3.	Nikhil Singh

## Material USed
1.	CONNECTING ARDUINO UNO/MEGA
2.	SPO2 (max 30100)
3.	RTD temperature sensor
4.	HEART RATE SENSOR(AD8232 ecg module)
5.	ECG STICKERS OR ELECTRODES
6.	BLOOD PRESSURE SENSOR (sunrom 1437)
7.	BLUETOOTH TERMINAL
8.	BATTERY (12 volt)
9.	Voltage regulator(7805)
10. Connecting wires and glue
11. T shirt

## Apparatus Details
1. ArduniUNo/Mega

2. Spo2(max 30100)
 
  This is a Pulse Oximeter module based upon Maxim's MAX30100 integrated IC which is an compact low cost integrated solution for measuring Heart Rate as well as Pulse oximeter.

MAX30100 sensor has two led's and a Photo-detector the two led's are used to emit two different wavelength of light. One led is a red led while the other one is an infrared led. The photo-detector is then used to sense the absorbance of the blood flowing through the finger tip. This signal is then processed using a low noise analog signal processing unit and then an internal micro-controller then converts it into digital output and gives out data in i2c protocol.

MAX-30100 Sensor Module has an inbuilt voltage regulator so it can be powered via 5 Volt and can be interfaced to any 5 volt micro-controllers, Arduino as well as Raspberry Pi.

3. RTD(MAXIM18B20)
It is the most simple and basic sensor in the whole monitor. It includes a Resistance temperature detector, and as temperature changes resistance changes leading to voltage output which then is sensed by Arduino and temperature is displayed.  

4. Heart rate monitor(AD8232ecg module)
 
The AD8232 SparkFun Single Lead Heart Rate Monitor is a cost-effective board used to measure the electrical activity of the heart. This electrical activity can be charted as an ECG or Electrocardiogram and output as an analog reading. ECGs can be extremely noisy, the AD8232 Single Lead Heart Rate Monitor acts as an op amp to help obtain a clear signal from the PR and QT Intervals easily.
The AD8232 is an integrated signal conditioning block for ECG and other biopotential measurement applications. It is designed to extract, amplify, and filter small biopotential signals in the presence of noisy conditions, such as those created by motion or remote electrode placement.

5. ECG STICKERSOR ELECTRODES
 
Electrocardiography  is the process of recording the electrical (actually muscle activity that is created from an electrical impulse in the synapses of the neural cells that are contained in the tissue of the heart) activity of the heart over a period of time using electrodes placed on the skin.

6. Blood pressure sensor(sunrom1437)
 
**Features**
- Intelligent automatic compression and decompression
-	Easy to operate, switching button to start measuring
-	60 store groups memory measurements
-	Can read single or all measures
-	3 minutes automatic power saving device
-	Intelligent device debugging, automatic power to detect
-	Local tests for : wrist circumference as 135-195mm
-	Large-scale digital liquid crystal display screen, Easy to Read Dsplay
- Fully Automatic, Clinical Accuracy, High-accuracy
-	Serial output data for external circuit processing or display.
- Power by External +5V DC

**Specification**
-	Working Voltage: +5V, 200mA regulated
-	Output Format :Serial Data at 9600 baud rate(8 bits data, No parity, 1 stop bits). Outputs three parameters in ASCII.
-	Sensing unit wire length is 2 meters

**Sensor Pinouts**
-	TX-OUT = Transmit output. Output serial data of 3V logic level, Usually connected to RXD pin of microcontrollers/RS232/USB-UART.
-	+5V = Regulated 5V supply input.
-	GND = Board Common Ground
-	+5V = Regulated 5V supply input.
-	GND = Board Common Ground

7. Bluetooth  terminal
 This device is used in our project for taking all sesors’s datas via help of android app.

8. Battery(12v)

9. Voltage regulator(7805)
A voltage regulator is an electronic circuit that provides a stable DC voltage independent of the load current, temperature and AC line voltage variations
                                    


## Final Image of our Monitor 
                    
## Result

## Future Scope
1.	We will add more sensors to measure more health parameters.
2.	We will increase the range of our device,i.e our device can give readings on the monitor when it is placed in the range of 5-6 meters with our device as its centre. We can use wi fi module instead of Bluetooth module.
3.	We will make the whole system on PCB instead of bread board,so that shirt becomes light and can be easily wearable(not disrupting any connections).
