int pulsantePin1 = A0;  // inposto il nome di A0 nel programma
int pulsantePin2 = A1;
int pulsantePin3 = A2;
int val1 = 1;  // pulsantepin varibile dove salvo il valore alto o basso letto da A0, impostato su 1 perche' all' in inizio lui ha 5 volt con una resistenza di pulup
int val2 = 1;
int val3 = 1;
int segnalePin1 = 7; // imposto il nome del pin 7 nel programma (movimento giostra)
int segnalePin2 = 8; // imposto il nome del pin 8 nel programma (suono giostra)
int segnalePin3 = 9;
int segnalePin4 = 10;
int segnalePin5 = 11;
int segnalePin6 = 12;
int a = 0;  // contatore per la proma giostra
int b = 0;  // contatore per la seconda giostra
int c = 0;  // contatore per la terza giostra
int alfa = 0;  // contatore per leggere la seriale e vedere i valori che legge ogni tot nel programma
int giostra1onmovimento = 0;  // variabile dove salvo cosa deve fare la giostra esempio movimento
int giostra2onmovimento = 0;
int giostra3onmovimento = 0;
int giostra1onsuono = 0;  // variabile dove salvo cosa deve fare la giostra esempio suono
int giostra2onsuono = 0;
int giostra3onsuono = 0;


void setup() {
  Serial.begin(115200);
  pinMode(pulsantePin1, INPUT );  // imposto come lettura il pin A0
  pinMode(pulsantePin2, INPUT );
  pinMode(pulsantePin3, INPUT );

  pinMode(segnalePin1, OUTPUT );  // imposto come ucita il pin 7 giostra1 in movimento 
  pinMode(segnalePin2, OUTPUT );  // imposto come ucita il pin 8 giostra1 con il suono
  pinMode(segnalePin3, OUTPUT );
  pinMode(segnalePin4, OUTPUT );
  pinMode(segnalePin5, OUTPUT );
  pinMode(segnalePin6, OUTPUT );
}

void loop() {
  val1 = digitalRead(pulsantePin1);  // leggi lo stato del pulsante (non premuto 1, premuto 0)
  val2 = digitalRead(pulsantePin2);
  val3 = digitalRead(pulsantePin3);

  if (val1 == 0){  // se il pulsante 1 è premuto
    giostra1onmovimento = 1;
  }
  
  if (giostra1onmovimento == 1 && a <= 1000){ // se il pulsante è stato premuto giostra1onmovimento va a 1 mi porta il pin 7 a 5 volt fino a che a non arriva a 1000. 1000 perche' il ritardo generale del programma è 30 millisecondi quindi ogni 30 millisecondi aumenta a di 1, per fare un secondo ci vogliono 1000 millisecondi quindi lui esegue il programma 33 volte in un secondo, dopo un secondo a è uguale a 33
    digitalWrite(segnalePin1, HIGH);
    a = a + 1; 
    }
  if (val1 == 0 && giostra1onmovimento == 1 && a >= 50){ // se il pulsante viene premuto , giovastra1onavanti è a 1, quindi il pulsante è gia' stato premuto una volta e il conteggio di a è arrivato a 50 piu' o meno 1 secondo e qualcosa allora fai partire anche la musica con 5 volt sul pin 8 
    digitalWrite(segnalePin2, HIGH);
  }
  
  if (a == 1000){  // se a è arrivato a 1000 metti l'uscita 7 e 8 a  0 volt e la varibile giosta1onavanti a 0
    digitalWrite(segnalePin1, LOW);
    digitalWrite(segnalePin2, LOW);
    giostra1onmovimento = 0;
    a = 0;
    }

  if (val2 == 0){
    giostra2onmovimento = 1;
  }
  if (val2 == 0 && giostra2onmovimento == 1 && b >= 50){
    digitalWrite(segnalePin4, HIGH);
  }
  if (giostra2onmovimento == 1 && b <= 1000){
    digitalWrite(segnalePin3, HIGH);
    b = b + 1;
    }
  if (b == 1000){
    digitalWrite(segnalePin3, LOW);
    digitalWrite(segnalePin4, LOW);
    giostra2onmovimento = 0;
    b = 0;
    }

  if (val3 == 0){
    giostra3onmovimento = 1;
  }
  if (val3 == 0 && giostra3onmovimento == 1 && c >= 50){
    digitalWrite(segnalePin6, HIGH);
  }
  if (giostra3onmovimento == 1 && c <= 1000){
    digitalWrite(segnalePin5, HIGH);
    c = c + 1;
    }
  if (c == 1000){
    digitalWrite(segnalePin5, LOW);
    digitalWrite(segnalePin6, LOW);
    giostra3onmovimento = 0;
    c = 0;
    }

   
  if (alfa >= 3){ // imposta la velocita' di stampa sulla seriale 30 millisecondi * 3 = ogni 90 millisecondi stampa
    Serial.print("val1:");
    Serial.println(val1);
    Serial.print("giostra1onmovimento:");
    Serial.println(giostra1onmovimento);
    Serial.print("a:");
    Serial.println(a);
    alfa = 0;
  }
  alfa = alfa + 1;
  delay(30); // tempo del programma impostato per evitare rimbalzo del pulsante ogni volta che viene premuto 

}      
  
