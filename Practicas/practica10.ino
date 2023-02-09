/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **  
**                   Práctica #10  Sensor capacitivo          **
***************************************************************/

int LED = 3;
int TTP223B = 4;

void setup() {
  pinMode(LED, OUTPUT);                    // LED como salida
  pinMode(TTP223B, INPUT);                 // TTP223B como entrada
}

void loop() {
  if (digitalRead(TTP223B) == HIGH) {      // Si el boton esta presionado
    digitalWrite(LED, HIGH);               // Enciende el LED
    Serial.println("Boton presionado");    // Imprime en el monitor serial
  } else {                                 // Si el boton no esta presionado
    digitalWrite(LED, LOW);                // Apaga el LED
    Serial.println("Boton no presionado"); // Imprime en el monitor serial
  }
  delay(100);                              // Espera 100 milisegundos
}


// Comentarios:

/*
El código define dos constantes enteras:

LED: Una constante entera con un valor de 3 que se utiliza para definir el pin del microcontrolador que se usará como salida para el LED.
TTP223B: Una constante entera con un valor de 4 que se utiliza para definir el pin del microcontrolador que se usará como entrada para el botón TTP223B.
El código tiene dos funciones principales: setup() y loop().

La función setup() se ejecuta una vez cuando se inicia el microcontrolador. Establece los modos de los pines LED y TTP223B como salida y entrada, respectivamente.

La función loop() es la función principal que se ejecuta repetidamente mientras el microcontrolador está en funcionamiento. En primer lugar, se lee el estado del botón TTP223B con la función digitalRead(). Si el botón está presionado y digitalRead() devuelve HIGH, se enciende el LED con la función digitalWrite() y se imprime "Boton presionado" en el monitor serial con la función Serial.println(). Si el botón no está presionado, se apaga el LED y se imprime "Boton no presionado" en el monitor serial. Finalmente, se espera 100 milisegundos con la función delay() antes de volver a iniciar la función loop().

Este código podría ser utilizado para controlar el encendido y apagado de un LED dependiendo del estado del botón TTP223B.

*/