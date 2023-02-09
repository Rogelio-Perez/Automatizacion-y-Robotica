/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **
**                   Práctica #10  Sensor Ultrasonico         **
***************************************************************/

int TRIGGER = 10;
int ECO = 9;
int LED = 3;
int DURACION;
int DISTANCIA;

void setup() {
  Serial.begin(9600); // Inicia el monitor serial
  pinMode(TRIGGER, OUTPUT); // TRIGGER como salida
  pinMode(ECO, INPUT); // ECO como entrada
  pinMode(LED, OUTPUT); // LED como salida
}

void loop() {
  // el valor de medicion lo entrega en centimetros
  digitalWrite(TRIGGER, HIGH); // Envia un pulso de 10 microsegundos
  delay(1); // Espera 1 milisegundo
  digitalWrite(TRIGGER, LOW); // Apaga el pulso

  DURACION = pulseIn(ECO, HIGH); // Mide el tiempo que tarda en regresar el pulso
  DISTANCIA = DURACION / 58.2; // Calcula la distancia en centimetros

  Serial.print("Distancia: "); // Imprime en el monitor serial
  Serial.print(DISTANCIA); // Imprime en el monitor serial

  if (DISTANCIA >= 0 && DISTANCIA <= 20)
  {
    digitalWrite(LED, HIGH); // Enciende el LED
    Serial.println(" cm - LED encendido"); // Imprime en el monitor serial
    delay(DISTANCIA * 25); // Espera el tiempo de distancia * 25
    digitalWrite(LED, LOW); // Apaga el LED
  }
  else
  {
    digitalWrite(LED, LOW); // Apaga el LED
    Serial.println(" cm - LED apagado"); // Imprime en el monitor serial
  }
}

// Comentarios:

/*
Este código es un programa escrito en lenguaje de programación C/C++ para el microcontrolador Arduino. Está utilizando la librería Arduino para controlar el hardware y el entorno de desarrollo integrado (IDE) de Arduino para programar el microcontrolador.

El código define 4 variables:

TRIGGER: Una constante entera con un valor de 10 que se utiliza para definir el pin del microcontrolador que se usará como trigger para el sensor de distancia.
ECO: Una constante entera con un valor de 9 que se utiliza para definir el pin del microcontrolador que se usará como eco para el sensor de distancia.
LED: Una constante entera con un valor de 3 que se utiliza para definir el pin del microcontrolador que se usará como salida para el LED.
DURACION y DISTANCIA: Variables enteras que se utilizarán para almacenar la duración y la distancia medida por el sensor de distancia, respectivamente.

El código tiene dos funciones principales: setup() y loop().

La función setup() se ejecuta una vez cuando se inicia el microcontrolador. Establece la velocidad de la comunicación serial en 9600 baudios, establece los modos de los pines TRIGGER, ECO y LED como salida, respectivamente, y comienza la comunicación serial.

La función loop() es la función principal que se ejecuta repetidamente mientras el microcontrolador está en funcionamiento. En primer lugar, enciende el pin TRIGGER durante 1 milisegundo y luego lo apaga. Luego, mide la duración de la señal de eco del sensor de distancia en el pin ECO y calcula la distancia a partir de la duración medida. Luego, la distancia se envía a través de la comunicación serial y se imprime en la terminal. Finalmente, si la distancia está dentro de un rango de 0 a 20 cm, se enciende el LED durante un tiempo proporcional a la distancia y luego se apaga.

Este código podría ser utilizado para medir la distancia a un objeto y controlar el encendido y apagado del LED dependiendo de la distancia medida.
*/