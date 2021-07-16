#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

Adafruit_BMP280 bmp;

void setup(){

    Serial.begin(115200);
    
    if (!bmp.begin(0x76)){

        Serial.print("Dispositivo não encontrado"); 
        
        while(1);
    }


}

void loop(){

    float temperatura_celsius = bmp.readTemperature();
    float pressao_Pa = bmp.readPressure();
    float pressao_atm = bmp.readPressure() / 101325.0F;
    float altitude = bmp.readAltitude(1013.25);
    
}