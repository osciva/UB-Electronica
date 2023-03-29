//Fitxer que relaciona text amb les freqüències de notes musicals
#include "notes_frequencies.h"


//Notes
//01
//Notes (): (C:Do, D:Re, E:Mi, F:Fa, G: Sol, A:La, B:Si)
unsigned int notes[] = {NA4,ND4,NF4,NG4,NA4,ND4,NF4,NG4,NE4,NG4,NC4,NF4,NE4,NG4,NC4,NF4,NE4,ND4,ND4};
//Duracio notes en millisegons
unsigned int duracio_notes[] = {6000,6000,1000,1000,4000,4000,1000,1000,12000,6000,6000,1000,1000,4000,6000,1000,1000,4000,6000};

unsigned int polsador = 4;
unsigned int altaveu = 8;
unsigned long temps = 0;

int tempsMinim = 36000;
int temporal = 0;
int compt = 0;



void setup() {
  Serial.begin(9600);
  pinMode(altaveu, OUTPUT);
}


void loop() {
  for(int i = 0; i < sizeof(duracio_notes); i++){
    
    tone(altaveu,notes[i],duracio_notes[i]);
    temps = millis();
    if(digitalRead(polsador) == HIGH && temps < (duracio_notes[i] + 700)){
      
      temporal += 1;
    }
    if(digitalRead(polsador) == HIGH && temps > (duracio_notes[i] + 700)){
      
      temporal = 0;
    }
    compt += temporal;
    delay(random(700,2500));
  }
  if(compt >= tempsMinim){
    
    Serial.println("Has guanyat!!!!");
    Serial.end();
  }else{
    
    Serial.println("Has perdut, més sort el pròxim cop!!!!");
    Serial.end();
  }

}
