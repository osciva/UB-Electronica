const int photodiode = A5;
const int bright_LED = 2;
unsigned long llindar = 500;
unsigned long tempslimit = 10000;
unsigned long photodiode_value;
unsigned long minim = 100;
unsigned long maxim = 900;
unsigned long temps;
int comptadorJ1 = 0;
int comptadorJ2 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 }

void loop() {
     photodiode_value = analogRead(5); // llegim la intensitat lluminosa que rep el fotodiode
     Serial.println("El fotodiode esta rebent una intensitat lluminosa de : ");
     Serial.println(photodiode_value); // imprimim per pantalla la intensitat lluminosa que rep el fotodiode

     // si la intensitat lluminosa que rep el fotodiode és superior o igual a la llindar però inferior al màxim  (és a dir, està en el rang de punts del J1), 
     // sumem 1 als punts del J1 i imprimim per pantalla el missatge "Punt per al jugador 1, actualment te : " 
     if (photodiode_value >= llindar && photodiode_value <= maxim){  
         Serial.println("Punt per al jugador 1, actualment te : ");
         comptadorJ1 = comptadorJ1 + 1;
         Serial.println(comptadorJ1);
         
         
     }
     // si la intensitat lluminosa que rep el fotodiode és inferior a la llindar però superior al mínim  (és a dir, està en el rang de punts del J2), sumem 1 als punts del 
     //J2 i imprimim per pantalla el missatge "Punt per al jugador 2, actualment te : " 
     else if (photodiode_value < llindar && photodiode_value >= minim){
         Serial.println("Punt per al jugador 2, actualment te : ");
         comptadorJ2 = comptadorJ2 + 1;
         Serial.println(comptadorJ2);
         
     }

     // Guardem el nombre de mil·lisegons passats des que la placa Arduino va començar a executar el programa actual en una variable anomenada temps
     temps = millis();
     if (temps>tempslimit){  // el programa finalitza en el moment en que temps > tempslimit
         Serial.println("S'ha acabat el temps... El guanyador es:");
         if (comptadorJ1 > comptadorJ2){
            Serial.println("jugador 1 ");
            exit(0);
         }
         else if(comptadorJ1 < comptadorJ2){
            Serial.println("jugador 2");
            exit(0);
         }else{
            Serial.println("Ningu, es un empat");
            exit(0);
         }
     }

     

     
     
}
