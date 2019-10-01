int GREEN = 6;
int RED = 5;
int PUSH1 = 4;
int PUSH2 = 2;
int PUSH3 = 3;

int piso = 1;

void lightLED(int floor);

void setup() {
  pinMode(PUSH1, INPUT);
  pinMode(PUSH2, INPUT);
  pinMode(PUSH3, INPUT);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
}

void loop() {
  digitalWrite(GREEN, HIGH);
  lightLED(piso);
  if (digitalRead(PUSH1) == HIGH){
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    delay (1000);
    if (piso == 2){
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      piso=1;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    }
    if (piso == 3){
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      piso=2;
      lightLED(piso);
      delay(1000);
      piso=1;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    } 
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  
  if (digitalRead(PUSH2) == HIGH){
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    delay (1000);
    if (piso == 1){
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      piso=2;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    }
    if (piso == 3){
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      piso=2;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    } 
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  
  if (digitalRead(PUSH3) == HIGH){
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    delay (1000);
    if (piso == 1){
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      piso=2;
      lightLED(piso);
      delay(1000);
      piso=3;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    }
    if (piso == 2){
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      piso=3;
      lightLED(piso);
      delay(1000);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      delay(1000);
    } 
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  
}

void lightLED(int floor){
  if (floor == 1){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  if (floor == 2){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
  }
  if (floor == 3){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
  }
}