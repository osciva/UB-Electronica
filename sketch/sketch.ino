//Variables globals
unsigned char pinlect=1;
unsigned char pindig=5;
//Configuració
void setup() {
 Serial.begin(9600);
 pinMode(pindig, INPUT_PULLUP);
 }
//Codi
void loop() {
 unsigned int control=0;
 rval=analogRead(pinlect); //Lectura tensió analògica al pin número ‘pinlect’
 control=digitalRead(pindig); //Lectura tensió digital (LOW, HIGH) al pin ‘pindig’
 //Enviem els valors a la connexió sèrie per graficar-los només si la lectura digital era LOW
 if (control==LOW) {
 Serial.print(rval);
 Serial.print(",");
 Serial.println(500);
 }
 if (rval>500) Serial.end(); //Finalitzem la connexió sèrie
 delay(100);
}
