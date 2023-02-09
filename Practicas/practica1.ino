/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **  
**                   Práctica #1  Sensor fotoresistivo        **
***************************************************************/

int LDR; 
int SENSOR = 0;
int INDICADOR = 4;

void setup() 
{
  Serial.begin(9600); // Inicia la comunicación serial
  pinMode(INDICADOR,OUTPUT); // LED como salida
  // analógicos no se tienen que definir
}

void loop() 
{
 LDR = analogRead(SENSOR); // Lee el valor del sensor
 Serial.println(LDR); // Imprime el valor del sensor
 if(LDR>500) // Si el valor del sensor es mayor a 500
 {
  Serial.println("Luz"); // Imprime en el monitor serial
  digitalWrite(INDICADOR, HIGH); // Enciende el LED
 }
 else // Si el valor del sensor es menor a 500
 {
  Serial.println("Oscuridad"); // Imprime en el monitor serial
  digitalWrite(INDICADOR, LOW); // Apaga el LED
 }
}

// Comentarios:

/*
Este código de Arduino es un programa sencillo que lee el valor de un sensor LDR (sensor de luz), y controla un LED según la intensidad de la luz.

En el código, se definen tres variables: LDR, SENSOR y INDICADOR. La variable SENSOR se establece en 0, lo que significa que el código leerá la entrada de un pin analógico específico. La variable INDICADOR se establece en 4, lo que significa que se controlará el estado de un pin digital específico.

En la función setup(), se establece la velocidad de transmisión serial a 9600 baudios, y se establece el pin INDICADOR como un pin de salida digital.

En la función loop(), el código lee el valor del sensor LDR mediante la función analogRead(SENSOR), y se almacena en la variable LDR. El valor se imprime a través de la función Serial.println(LDR). Luego, se comprueba si el valor de LDR es mayor a 500, y si es así, se establece el pin INDICADOR en un estado alto (encendido) mediante la función digitalWrite(INDICADOR, HIGH). Si el valor es menor o igual a 500, se establece el pin INDICADOR en un estado bajo (apagado) mediante la función digitalWrite(INDICADOR, LOW). Este proceso se repite continuamente en el bucle loop().
*/

