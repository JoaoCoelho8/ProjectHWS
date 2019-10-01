int pinos[] = {13, 12, 11, 10, 9, 8, 7};
int pad_numbers[10][7] = {{0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
}; 
int GREEN = 5;
int RED = 6;
int BLUE = 2;
int OK_BUTTON = 4;
int NEW_BUTTON = 3;
int learning = 0;

int key[4] = {1, 2, 3, 4};
int nKey = 4;
int count = 0;
int valPot = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(OK_BUTTON, INPUT);
  pinMode(NEW_BUTTON, INPUT);
  Serial.begin(9600);
}

void printcode(){
  int k;
  Serial.println();
  for(k=0; k<4; k++)
  {Serial.print(key[k]);
  }
  Serial.println();
}
void loop() {
  printcode();
  //Serial.println(analogRead(A0));
  valPot = analogRead(A0);
  valPot = map ( valPot, 0, 1023, 9, 0);
  print_number (valPot);
  if (count == nKey) {
    digitalWrite(GREEN, HIGH);
    delay(2000);
    digitalWrite(GREEN, LOW);
    count = 0;
  }

  Serial.println(learning);
  
  if (digitalRead(OK_BUTTON) == LOW) {
    if (learning == 1) {
      key[count] = valPot;
      count++;
      delay(1000);
      if (count == 4) {
        learning = 0;
        digitalWrite(BLUE, LOW);
      }
    } else {
      if (key[count] == valPot) {
        blink (GREEN);
        count++;
      } else {
        count = 0;
        blink (RED);
      }
    }

  }

  if (digitalRead(NEW_BUTTON) == LOW) {
    digitalWrite(BLUE, HIGH);
    learning = 1;
    //digitalWrite(BLUE, LOW);
  }
}

int print_number (int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite (pinos[i] , pad_numbers[number][i]);
  }
}

int blink (int led) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}