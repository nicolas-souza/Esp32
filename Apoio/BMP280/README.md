#BMP280
Sensor barométrico e de temperatura, capaz de medir altitude

- Algumas considerações
    - É fundamental informar o endereço do protocolo I2C
    - O valor de pressão é retornado em Pa 
    - A temperatura é retornada em °C
    - A altitude é retornada em metros (m)
    - A altidude não é medida, é aproximada com base nos valores nos outros valores 