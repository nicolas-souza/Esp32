#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;  

void loop(){

    Serial.begin(115200);

    Wire.begin();
    lightMeter.begin();
}

void loop(){

    float luminosidade_lux = lightMeter.readLightLevel();
}