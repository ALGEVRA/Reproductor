
// Team 8 Reproductor


#include <mega328p.h>
#include <delay.h>

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
#define REST 0


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

int melody1[] = {
    NOTE_C4, 4,  NOTE_C4, 4,  NOTE_G4, 4,  NOTE_G4, 4,  NOTE_A4, 4,  NOTE_A4, 4,  NOTE_G4, 2,
  NOTE_F4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_E4, 4,  NOTE_D4, 4,  NOTE_D4, 4,  NOTE_C4, 2,
  NOTE_G4, 4,  NOTE_G4, 4,  NOTE_F4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_E4, 4,  NOTE_D4, 2,
  NOTE_G4, 4,  NOTE_G4, 4,  NOTE_F4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_E4, 4,  NOTE_D4, 2,
  NOTE_C4, 4,  NOTE_C4, 4,  NOTE_G4, 4,  NOTE_G4, 4,  NOTE_A4, 4,  NOTE_A4, 4,  NOTE_G4, 2,
  NOTE_F4, 4,  NOTE_F4, 4,  NOTE_E4, 4,  NOTE_E4, 4,  NOTE_D4, 4,  NOTE_D4, 4,  NOTE_C4, 2
};


int melody2[] = {
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_D4, 4, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 2,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_D4, 4, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 2,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_D4, 4, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 2,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_D4, 4, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 2,
  NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_E4, 4
};

int notes1 = sizeof(melody1) / sizeof(melody1[0]) / 2;
int notes2 = sizeof(melody2) / sizeof(melody2[0]) / 2;


// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = 1714;

int divider = 0, noteDuration = 0;

void Tono(float frec){
    float Cuentas;
    unsigned int CuentasEnt;
                          
    
    Cuentas=100000.0/frec;   //500000 SE CAMBIA POR 8 MILLONES PORQUE SE USAR� RELOJ DE 16MHz
    
    CuentasEnt=Cuentas+0.5; //se queda con la parte entera, cuando a un entero le asignas un flotante 
    
    
    OCR1AH=(CuentasEnt-1)/256;
    OCR1AL=(CuentasEnt-1)%256; 
    DDRB.1 = 1;
    TCCR1A=0x40;
    TCCR1B=0x09; //Pre-escalador CK
           
}
void noTono(){
    TCCR1A =0;
    TCCR1B=0; //Apaga el Timer
    PORTB.1=0;
}



void main(void)
{

unsigned char button1, button2;

  unsigned int thisNote;
  CLKPR = 0x80;
  CLKPR = 0x04;

  DDRC.0 = 0; // Configura el pin PC0 como entrada
  DDRC.1 = 0; // Configura el pin PC1 como entrada
  PORTC.0 = 1; // Habilita resistencia de pull-up en PC0
  PORTC.1 = 1; // Habilita resistencia de pull-up en PC1
  
  while (1)
  {
    button1 = PINC.0; // Lee el estado del bot�n 1
    button2 = PINC.1; // Lee el estado del bot�n 2

    if (button1 == 0 && button2==1 )
    {
      // Si el bot�n 1 est� presionado, reproduce la canci�n 1
      for (thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2)
      { 
           button1 = PINC.0; // Lee el estado del bot�n 1
    button2 = PINC.1; // Lee el estado del bot�n 2
    
       if (button2==0 && button1 == 1){ 
       break;
     }  
        if(button2==1 && button1 == 1 )
        {
         // Calcula la duraci�n de cada nota
            divider = melody1[thisNote + 1];
            if (divider > 0)
             {
              // Nota regular, procede normalmente
                noteDuration = (wholenote) / divider;
             }
            else if (divider < 0)
             {
                // �Las notas punteadas se representan con duraciones negativas!
                divider = (-1) * divider;
                noteDuration = (wholenote) / divider;
                noteDuration = 1.5 * noteDuration; // Aumenta la duraci�n a la mitad para notas punteadas
             }

            // Reproduce la nota durante el 90% de la duraci�n, dejando el 10% restante como una pausa
            Tono(melody1[thisNote]);
            delay_ms(noteDuration * 0.9);

            // Espera la duraci�n especificada antes de reproducir la siguiente nota
            delay_ms(noteDuration * 0.1);

            // Detiene la generaci�n de la forma de onda antes de la siguiente nota
            noTono();
        }   
        
      if (button2==0 && button1 == 1){ 
       break;
     //  thisNote=notes1*2;
     } 
     
      }
    }     
    
     if (button2 == 0 && button1==1 )
    {
      // Si el bot�n 2 est� presionado, reproduce la canci�n 2
      for (thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2)
      { 
       button1 = PINC.0; // Lee el estado del bot�n 1
    button2 = PINC.1; // Lee el estado del bot�n 2     
       if (button1==0 && button2 == 1 ){ 
       break;
       }  
       
        if (button1==1 && button2 == 1 )
        {
            // Calcula la duraci�n de cada nota
            divider = melody2[thisNote + 1];
            if (divider > 0)
            {
                // Nota regular, procede normalmente
                noteDuration = (wholenote) / divider;
            }
            else if (divider < 0)
            {
                // �Las notas punteadas se representan con duraciones negativas!
                divider = (-1) * divider;
                noteDuration = (wholenote) / divider;
                noteDuration = 1.5 * noteDuration; // Aumenta la duraci�n a la mitad para notas punteadas
            }

                // Reproduce la nota durante el 90% de la duraci�n, dejando el 10% restante como una pausa
                Tono(melody2[thisNote]);
                delay_ms(noteDuration * 0.9);

                // Espera la duraci�n especificada antes de reproducir la siguiente nota
                delay_ms(noteDuration * 0.1);

                // Detiene la generaci�n de la forma de onda antes de la siguiente nota
                noTono();
        } 
        if (button1==0 && button2 == 1 ){ 
       break;
       }  
      }
    }
  }
}                                                                       