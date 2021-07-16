# Protocolo I2C

- É um protocolo de comunicação que permite a comunicação de diversos dispositivos através de uma lógica mestre/escravo
- A literatura diz que pode haver até 127 escravos, na prática apenas 112 
- O escravo só envia dados se o mestre solicitar
- O dispositivo mestre precisa saber o endereço de cada escravo
- Cada escravo costuma possuir um endereço próprio determinado pelo fabricante

## I2C no Esp32
- PINO SDA (GPIO 21)
- PINO SCL (GPIO 22)


O algoritmo presente no arquivo i2c possibilita encontrar o endereço correto se houver necessidade de estabelecer o endereço manualmente