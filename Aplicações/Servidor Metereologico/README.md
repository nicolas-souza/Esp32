# Servidor do Tempo 

## Funcionamento
- O ESP32 através da biblioteca Wifi é capaz de criar um servidor web
- Dentro do algoritmo é montado um arquivo de documento HTML que é servido ao cliente (navegador)
- É acessível somente dentro da rede Wifi 

### Dispositivos 
- ESP32
- BMP280
- BH1750

### Protocolos/Padrões de Comunicação
- I2C
- WiFi

### Bibliotecas empregadas
- WiFi.h
- Wire.h
- Adafruit_BMP280.h
- Adafruit_Sensor.h
- BH1750.h