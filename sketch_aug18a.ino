#define ledred 5 
#define ledblue 2
#define ledgreen 0
#define buttonBlack 12
#define buttonYellow 14
unsigned long tempoAnterior = 0;
unsigned long tempoAnteriorTwo = 0;

const long intervalOne = 200;
const long intervalTwo = 430;

int sai = 0;
int cor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(buttonBlack, INPUT_PULLUP);
  pinMode(buttonYellow, INPUT_PULLUP);

  Serial.begin(9600);
}

void pisca(){
  if (cor == 0){
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblue, LOW)                ;
    digitalWrite(ledgreen, LOW);
    delay(200);
    digitalWrite(ledred, LOW);
    delay(200);
  }else{
    digitalWrite(ledred, LOW);
    digitalWrite(ledblue, HIGH)                ;
    digitalWrite(ledgreen, LOW);
    delay(200);
    digitalWrite(ledblue, LOW);
    delay(200);
  }
}

void btYellow(){
  while(sai==0){
    digitalWrite(ledred, LOW);
    digitalWrite(ledblue, LOW);
    digitalWrite(ledgreen, HIGH);
    delay(500);
    if(digitalRead(buttonYellow) == HIGH){
      sai=1;
    }
  }
}

void inverte(){
  if (cor == 0){
    cor=1;
  }else{
    cor=0;
  }
}

void loop() {

  unsigned long tempoAtual = millis();
  
  //200
  //430

  
  if (tempoAtual - tempoAnterior >= intervalOne) {
    tempoAnterior = tempoAtual;

    if (digitalRead(ledblue) == HIGH) {
      digitalWrite(ledblue, LOW);
    } else {
      digitalWrite(ledblue, HIGH);
    }

  }


    if (tempoAtual - tempoAnteriorTwo >= intervalTwo) {
    tempoAnteriorTwo = tempoAtual;

    if (digitalRead(ledred) == HIGH) {
      digitalWrite(ledred, LOW);
    } else {
      digitalWrite(ledred, HIGH);
    }

  }
}
