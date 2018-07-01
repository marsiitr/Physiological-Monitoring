#include <Arduino.h>
#include "algorithm.h"
#include "max30102.h"

/*//if Adafruit Flora development board is chosen, include NeoPixel library and define an NeoPixel object
  #if defined(ARDUINO_AVR_FLORA8)
  #include "adafruit_neopixel.h"
  #define BRIGHTNESS_DIVISOR 8  //to lower the max brightness of the neopixel LED
  Adafruit_NeoPixel LED = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);
  #endif*/
//int rstpin = 8;

#define MAX_BRIGHTNESS 255

#if defined(ARDUINO_AVR_UNO)
//Arduino Uno doesn't have enough SRAM to store 100 samples of IR led data and red led data in 32-bit format
//To solve this problem, 16-bit MSB of the sampled data will be truncated.  Samples become 16-bit data.
uint16_t aun_ir_buffer[50]; //infrared LED sensor data
uint16_t aun_red_buffer[50];  //red LED sensor data
#else
uint32_t aun_ir_buffer[100]; //infrared LED sensor data
uint32_t aun_red_buffer[100];  //red LED sensor data
#endif
int32_t n_ir_buffer_length; //data length
int32_t n_spo2;  //SPO2 value
int8_t ch_spo2_valid;  //indicator to show if the SPO2 calculation is valid
int8_t ch_hr_valid;
int32_t n_heart_rate; //heart rate value
uint8_t uch_dummy;


// the setup routine runs once when you press reset:
void setup() {
  //pinMode(rstpin,OUTPUT);
  //digitalWrite(rstpin,HIGH);
  /*#if defined(ARDUINO_AVR_LILYPAD_USB)
    pinMode(13, OUTPUT);  //LED output pin on Lilypad
    #endif

    #if defined(ARDUINO_AVR_FLORA8)
    //Initialize the LED
    LED.begin();
    LED.show();
    #endif*/

  maxim_max30102_reset(); //resets the MAX30102
  // initialize serial communication at 115200 bits per second:
  Serial.begin(9600);
  pinMode(6, INPUT);  //pin D10 connects to the interrupt output pin of the MAX30102
  delay(1000);
  maxim_max30102_read_reg(REG_INTR_STATUS_1, &uch_dummy); //Reads/clears the interrupt status register
  uch_dummy = Serial.read();
  maxim_max30102_init();  //initialize the MAX30102

  spo2_init();
}

void spo2_init()
{
  uint32_t un_min, un_max, un_prev_data, un_brightness;  //variables to calculate the on-board LED brightness that reflects the heartbeats
  int32_t i;
  float f_temp;

  un_brightness = 0;
  un_min = 0x3FFFF;
  un_max = 0;

  n_ir_buffer_length = 50; //buffer length of 100 stores 4 seconds of samples running at 25sps

  //read the first 100 samples, and determine the signal range
  for (i = 0; i < n_ir_buffer_length; i++)
  {
    while (digitalRead(5) == 1); //wait until the interrupt pin asserts
    maxim_max30102_read_fifo((aun_red_buffer + i), (aun_ir_buffer + i)); //read from MAX30102 FIFO

    if (un_min > aun_red_buffer[i])
      un_min = aun_red_buffer[i]; //update signal min
    if (un_max < aun_red_buffer[i])
      un_max = aun_red_buffer[i]; //update signal max
  }
  un_prev_data = aun_red_buffer[i];
  //calculate heart rate and SpO2 after first 100 samples (first 4 seconds of samples)
  maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_spo2, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);

}
// the loop routine runs over and over again forever:
void loop() {

//  while (1)
//  {
 uint32_t un_min, un_max, un_prev_data, un_brightness;  //variables to calculate the on-board LED brightness that reflects the heartbeats
  int32_t i;
  float f_temp;
   i = 0;
    un_min = 0x3FFFF;
    un_max = 0;

    //dumping the first 25 sets of samples in the memory and shift the last 75 sets of samples to the top
    for (i = 12; i < 50; i++)
    {
      aun_red_buffer[i - 12] = aun_red_buffer[i];
      aun_ir_buffer[i - 12] = aun_ir_buffer[i];

      //update the signal min and max
      if (un_min > aun_red_buffer[i])
        un_min = aun_red_buffer[i];
      if (un_max < aun_red_buffer[i])
        un_max = aun_red_buffer[i];
    }

    //take 25 sets of samples before calculating the heart rate.
    for (i = 37; i < 50; i++)
    {
      un_prev_data = aun_red_buffer[i - 1];
      while (digitalRead(5) == 1);
      digitalWrite(9, !digitalRead(9));
      maxim_max30102_read_fifo((aun_red_buffer + i), (aun_ir_buffer + i));
      String s = String(n_spo2);

      if (ch_spo2_valid)
        Serial.println(s);
    }
    maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_spo2, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);
//  }
}
