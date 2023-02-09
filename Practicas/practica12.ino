/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **  
**                   Práctica #12  LED RGB                    **
***************************************************************/

int LB =9;
int LR =10;
int LG =11;

void setup() 
{
  pinMode(LR, OUTPUT); // LED como salida
  pinMode(LG, OUTPUT); // LED como salida
  pinMode(LB, OUTPUT); // LED como salida
}

void loop() 
{
  Serial.println("Ciclo de colores");
  analogWrite(LR,255); analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //rojo
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,255); analogWrite(LG,100); analogWrite(LB,0);    delay(500); //naranja
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,255); analogWrite(LG,255); analogWrite(LB,0);    delay(500); //amarillo
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,0);   analogWrite(LG,255); analogWrite(LB,0);    delay(500); //verde
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,0);   analogWrite(LG,255); analogWrite(LB,255);  delay(500); //cian
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,255);  delay(500); //azul
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"
  analogWrite(LR,100); analogWrite(LG,0);   analogWrite(LB,255);  delay(500); //morado
  analogWrite(LR,0);   analogWrite(LG,0);   analogWrite(LB,0);    delay(500); //"negro"

}

// Comentarios:

/*
Este código hace uso de tres pines (9, 10, 11) para controlar tres LEDs (rojo, verde, y azul) para crear un efecto de ciclo de colores.

El modo de los pines se establece en el método "setup()" y luego en el método "loop()" se establecen los valores de intensidad para cada LED utilizando la función "analogWrite()" y se agrega un retardo usando la función "delay()".

Este código creará un efecto ciclante de los colores rojo, naranja, amarillo, verde, cian, azul, morado, y un estado "negro" (cuando todos los LEDs están apagados).
*/
