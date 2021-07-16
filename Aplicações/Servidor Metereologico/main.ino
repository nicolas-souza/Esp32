#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h> 

BH1750 lightMeter; 

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP280 bmp; 


const char* ssid     = "";
const char* password = "";

WiFiServer server(80);

String header;

unsigned long tempo_atual = millis();
unsigned long tempo_anterior = 0; 
const long tempo_conex = 2000;

void setup() {

    Serial.begin(115200);
    
    //inicialização dos sensores
    Wire.begin();
    lightMeter.begin();
    bmp.begin(0x76); 
 
    //conexão a rede wi-fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
  
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }//só permite a continuidade se houver conexão

    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println("End de IP: ");
    Serial.println(WiFi.localIP());
    server.begin();
}

void loop(){
      
      WiFiClient client = server.available();   

      if (client) { 

        tempo_atual = millis();
        tempo_anterior = tempo_atual;

        Serial.println("Novo cliente");          
        String currentLine = "";                
        
        while (client.connected() && tempo_atual - tempo_anterior <= tempo_conex){

            tempo_atual = millis();
            if (client.available()) {             
                char c = client.read();             
                Serial.write(c);                    
                header += c;
            
                if (c == '\n'){
                    if (currentLine.length() == 0) {
              
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();

                        // Inicio do arquivo HTML
                        client.println("<!DOCTYPE html><html>");
                        client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                        client.println("<link rel=\"icon\" href=\"data:,\">");
                        client.println("<meta charset=\"utf-8\"/>");

                        //CSS
                        client.println("<style>body { text-align: center; font-family: \"Trebuchet MS\", Arial;}");
                        client.println("table { border-collapse: collapse; width:35%; margin-left:auto; margin-right:auto; }");
                        client.println("th { padding: 12px; background-color: #0043af; color: white; }");
                        client.println("tr { border: 1px solid #ddd; padding: 12px; }");
                        client.println("tr:hover { background-color: #000000; }");
                        client.println("td { border: none; padding: 12px; }");
                        client.println(".sensor { color:black; font-weight: bold; background-color: #ffffff; padding: 1px; }");

                        client.println("</style></head>");

                        client.println("<body><h1>Servidor do Tempo</h1>");
                        client.println("</style></head><body><h4>Nicolas de Souza</h4>");
                        client.println("<table><tr><th>Variável</th><th>Valor</th></tr>");

                        client.println("<tr><td>Temp. Celsius</td><td><span class=\"sensor\">");
                        client.println(bmp.readTemperature());
                        client.println(" &degC</span></td></tr>");     

                        client.println("<tr><td>Pressure</td><td><span class=\"sensor\">");
                        client.println(bmp.readPressure() / 101325.0F);
                        client.println(" atm</span></td></tr>");

                        client.println("<tr><td>Luminosidade</td><td><span class=\"sensor\">");
                        client.println(lightMeter.readLightLevel());
                        client.println(" Lux</span></td></tr>");

                        client.println("</body></html>");

                        client.println();

                        break; //força saída do while
                    } else { 
                        currentLine = "";
                    }
                } else if (c != '\r') {  
                    currentLine += c;      
                }
            }
        }
    
        header = "";
        
        //encerra conexão
        client.stop();
        Serial.println("Cliente disconnectado");
        Serial.println("");

    }//se não houver cliente nada acontece
}