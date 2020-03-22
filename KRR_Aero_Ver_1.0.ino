//Libraries
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

//Initialize libraries and setup MUX I2C address
Adafruit_BMP085 bmp;
#define TCAADDR 0x70

void setup() {
  Serial.begin(9600);

  //Initialize individual Sensors
  tcaselect(0);
  bmp.begin();
  tcaselect(1);
  bmp.begin();
}

//Function to set MUX port
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void loop() {
  
  //Read + display pressures
  tcaselect(0);
  Serial.println(bmp.readPressure());
  tcaselect(1);
  Serial.println(bmp.readPressure());
}
