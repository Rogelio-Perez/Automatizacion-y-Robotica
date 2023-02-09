/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **  
**           Práctica #2  Sensor de humedad y temperatura     **
***************************************************************/

#include <DHT.h>    // Librería para el sensor DHT22
#include <DHT_U.h>  // Librería para el sensor DHT22

int SENSOR = 5;
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT22);   //objeto dht (pin de conexión, modelo de sensor)

void setup() 
{
  Serial.begin(9600); // Inicia la comunicación serial
  dht.begin(); // Inicia el sensor
  Serial.print("Práctica de uso de sensor de temperatura y humedad"); // Imprime en el monitor serial
  Serial.println(); // Imprime en el monitor serial
}

void loop() 
{
  TEMPERATURA = dht.readTemperature(); // Lee el valor de temperatura
  HUMEDAD = dht.readHumidity(); // Lee el valor de humedad

  Serial.print("Medición de temperatura: "); // Imprime en el monitor serial
  Serial.print(TEMPERATURA); // Imprime en el monitor serial
  Serial.println(); // Imprime en el monitor serial
  Serial.print("Medición de humedad: "); // Imprime en el monitor serial
  Serial.print(HUMEDAD); // Imprime en el monitor serial
  Serial.println(); // Imprime en el monitor serial
  delay(5000); // Espera 5 segundos
  Serial.flush(); // Limpia el monitor serial
}

// Comentarios:

/*
Este código de Arduino controla un sensor de temperatura y humedad DHT22 conectado al pin 5. Utiliza dos librerías, DHT.h y DHT_U.h, que permiten trabajar con el sensor DHT22.

El código primero inicia la comunicación serial a una velocidad de 9600 baudios y luego inicia el sensor DHT22. En el bucle principal, se leen los valores de temperatura y humedad del sensor y se imprimen en el monitor serial. Después, se espera 5 segundos antes de volver a leer los valores. La función "flush" limpia el monitor serial antes de la siguiente lectura.
*/

