/***************************************************************
**            Benemérita Universidad Autónoma de Puebla       **
**               Automatización y Robótica Otoño 2022         **
**                        Perez Mena Rogelio                  **
**                 Sereno Casas Carlos Emiliano               **  
**                   Práctica #13  BUZZER                     **
***************************************************************/

// pines invertidos, de frente son voltaje, gnd y señal, de izquierda a derecha
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0
int SENSOR = 0;
int BUZZ = 3;
int VALOR = 10;

int BTNPIN = 0;
int btnValue = 1;
int setBtnValue;

int NUM = 1;

void setup() 
{
  Serial.begin(9600); // Inicia la comunicación serial
  pinMode(BUZZ,OUTPUT); // Configura el pin 3 como salida
  pinMode(BTNPIN, INPUT);
}

int melodia1[]=
{
  NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_C5,
  NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,
  NOTE_E5,NOTE_E5,NOTE_E5,NOTE_F5,NOTE_C5,
  NOTE_A4,NOTE_F4,NOTE_C5,NOTE_A4,
  
  NOTE_A5, NOTE_A4,NOTE_A4,NOTE_A5,NOTE_GS5,NOTE_G5, 
  NOTE_DS5,NOTE_D5,NOTE_DS5,REST,  NOTE_A4,NOTE_DS5,NOTE_D5,NOTE_CS5,

  NOTE_C5,NOTE_B4,NOTE_C5,REST,NOTE_F4,NOTE_GS4,NOTE_F4,NOTE_A4,
  NOTE_C5,NOTE_A4,NOTE_C5,NOTE_E5}; // Notas de la melodía
int duraciones1[]=
{
  2, 2, 2, 4, 8,
  2, 4, 8, 1,
  2, 2, 2, 4, 8,
  2, 4, 8, 1,
  
  2, 4, 8, 2, 4, 8, 
  8, 8, 4, 4, 4, 2, 4, 8,

  8, 8, 8, 4, 4, 2, 4, 8,
  2, 4, 8, 1
  }; // Duración de las notas
int melodia2[]=
{
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST
};
int duraciones2[]=
{
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 2, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 2, 2
};

int melodia3[]=
{
  NOTE_E5,NOTE_E5,REST,NOTE_E5,REST,NOTE_C5,NOTE_E5,
  NOTE_G5,REST,NOTE_G4,REST,
   
  NOTE_C5,NOTE_G4,REST,NOTE_E4,
  NOTE_A4,NOTE_B4,NOTE_AS4,NOTE_A4,
  NOTE_G4,NOTE_E5,NOTE_G5,NOTE_A5,NOTE_F5,NOTE_G5,
  REST,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_B4,
  
  NOTE_C5,NOTE_G4,REST,NOTE_E4,
  NOTE_A4,NOTE_B4,NOTE_AS4,NOTE_A4,
  NOTE_G4,NOTE_E5,NOTE_G5,NOTE_A5,NOTE_F5,NOTE_G5,
  REST,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_B4
  };
int duraciones3[]=
{
  8, 8, 8, 8, 8, 8, 8, 
  4, 4, 8, 4, 
  
  4, 8, 4, 4, 
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  
  4, 8, 4, 4, 
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4
  };
void loop() 
{
  setBtnValue = digitalRead(BTNPIN); // Lee el estado del boton
  VALOR = analogRead(SENSOR); // Lee el valor del sensor
  Serial.print("Valor de SENSOR: ");
  Serial.println(VALOR);

  // Al apretar el boton entrar al IF

  if (setBtnValue == 0) // Si el boton esta apretado
  {
    Serial.println("Button pressed");
    if (VALOR < 600) // Si el valor es menor a 600
    {
        Serial.println("Melodia numero 1");
        for(int i=0; i<44;i++) // Reproduce la melodía
        {
          int duracion = 1000/duraciones1[i]; // Calcula la duración de la nota
          tone(BUZZ,melodia1[i],duracion); // Emite la nota
          int pausa=duracion*1.3; // Calcula la pausa entre notas
          delay(pausa); // Espera la duración de la nota más la pausa
          noTone(BUZZ); // Apaga el buzzer
        }
        delay(5000); // Espera 5 segundos antes de volver a empezar
    }
    else if (VALOR > 850) // Si el valor es mayor a 850
    {
        Serial.println("Melodia numero 2");
        for(int i=0; i<76;i++) // Reproduce la melodía
        {
          int duracion = 1000/duraciones2[i]; // Calcula la duración de la nota
          tone(BUZZ,melodia2[i],duracion); // Emite la nota
          int pausa=duracion*1.3; // Calcula la pausa entre notas
          delay(pausa); // Espera la duración de la nota más la pausa
          noTone(BUZZ); // Apaga el buzzer
        }
        delay(5000); // Espera 5 segundos antes de volver a empezar

    }
    else // Si el valor está entre 600 y 850
    {
        Serial.println("Melodia numero 3");
        for(int i=0; i<44;i++) // Reproduce la melodía
        {
          int duracion = 1000/duraciones3[i]; // Calcula la duración de la nota
          tone(BUZZ,melodia3[i],duracion); // Emite la nota
          int pausa=duracion*1.3; // Calcula la pausa entre notas
          delay(pausa); // Espera la duración de la nota más la pausa
          noTone(BUZZ); // Apaga el buzzer
        }
        delay(5000); // Espera 5 segundos antes de volver a empezar
    }
  }

  else // Si el boton no esta apretado
  {
    Serial.println(".:MUSIC OFF:.");
  }
  
}
// Comentarios:
/*
Lo que este codigo hace es definir constantes de frecuencia de notas musicales y luego las usa en un arreglo de melodia. 
Establece un pin de salida para el buzzer y un pin de entrada para un sensor. 
En el método setup(), inicializa la transmisión serial a una tasa de 9600 baudios y establece el modo de pin del buzzer como salida. 
En el futuro, estos valores podrían ser utilizados para hacer sonar el buzzer con una melodía determinada.
*/