const int ldrPin = A5;
const int buttonPin = 2;

int buttonState = 0;
unsigned long intents = 0;
unsigned long encerts = 0;

unsigned long llindar = 800;
unsigned long tempslimit = 60000;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(buttonPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrStatus = analogRead(ldrPin);
  buttonState = digitalRead(buttonPin);
  unsigned long temps = millis();
  if ((ldrStatus < llindar) && (buttonState == LOW)) {
    // en el cas que el jugador 1 hagi fet l'intent de baixar per sota la intensitat lluminosa llindar i jugador 2 hagi accionat el pulsador
    intents = intents + 1;
    encerts = encerts + 1;
     // falta la variable control per evitar el problema explicat més abaix

  } else if ((ldrStatus < llindar) && (buttonState == HIGH)) {
    // en el cas que el jugador 1 hagi fet l'intent de baixar per sota la intensitat lluminosa llindar però jugador 2 no hagi accionat el pulsador
    intents = intents + 1;
    

    // el problema de comprovar cada 10 ms si es dóna aquesta condició és que el jugador 1 pot aconseguir estar durant 50 ms per sota la intensitat llindar i després decideix no 
    // fer res més durant el temps límit, pot guanyar igualment. I a l'inrevés, si jugador 2 prem el botó 1 cop, però el jugador 1 està fent que lluminositat actual < lluminositat 
    // llindar durant més de 30 ms, el jugador 2 guanya automaticament per això utilitzem delays de 3s

     // falta la variable control per evitar el problema explicat anteriorment

  } else if ((ldrStatus >= llindar) && (buttonState == LOW)) {
    // en el cas que el jugador 2 hagi accionat el pulsador però la intensitat lluminosa en aquell moment > intensitat lluminosa llindar
    intents = intents + 1;
    
    // falta la variable control per evitar el problema explicat anteriorment

  }
  if ( temps > tempslimit || encerts >=3 ) { // en el cas que s'acabi el temps o el jugador 2 encerti 3 cops entrem al pas final
    if (encerts >= 3) {                      // en el cas que haguem entrat per encertar 3 cops, vol dir que el jugador 2 ha guanyat
      Serial.println("Jugador 2 guanya");
      exit(0);
    }else if(intents<5){                     // en el cas que haguem entrat perquè s'ha acabat el temps, si el jugador 1 no ha fet el mínim d'intents, vol dir que el jugador 2 ha guanyat
      Serial.println("Jugador 2 guanya");
      exit(0);
    } else {                                 // en el cas que haguem entrat perquè s'ha acabat el temps, com l'única casuística que queda és que el jugador 1 ha superat el mínim d'intents,
      Serial.println("Jugador 1 guanya");    // i el jugador 2 no ha fet 3 encerts vol dir que el jugador 1 ha guanyat
      exit(0);
    }
  }
  delay(10);                                 // quan acabem el loop(), per a evitar que es torni a executar automàticament, possem un delay de 10 ms, tal i com diu l'enunciat:
}                                            // "Realitzeu cada mesura de la tensió cada 10ms"
