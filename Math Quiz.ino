#include <Servo.h>

 #define NOTE_C4 262
 #define NOTE_D4 294
 #define NOTE_E4 330
 #define NOTE_F4 349
 #define NOTE_G4 392
 #define NOTE_A4 440
 #define NOTE_B4 494
 #define NOTE_C5 523

Servo myServo;
int GREEN = 6;
int RED = 5;
int game = 1;
int num1 = 0;
int num2 = 0;
int result;
int answer = 0;
int angle = 0;
int question = 8;
char buffer[100];
const int kPinSpeaker = 9;


void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  myServo.attach(4);
  myServo.write(0);
  pinMode(kPinSpeaker, OUTPUT);
  
}


void loop() {
  
  if (game == 1){
    num1 = random(11);
    num2 = random(11);
    sprintf(buffer, "Indique o resultado da soma: %d+%d ", num1, num2);
    Serial.println (buffer);
    game = 0;
  }
  
  if (Serial.available()>0 && game == 0){
    result = Serial.parseInt();
    if( (num1+num2) == result ){
      Serial.print ("Resposta: ");
      Serial.println (result);
      Serial.println ("Resultado CORRECTO!!");
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      answer++;
      angle = (180 / 8) * answer;
      myServo.write(angle);
      delay(15);
    }else{
      Serial.print ("Resposta: ");
      Serial.println (result);
      Serial.println ("Resultado INCORRECTO!!");
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      answer=0;
      myServo.write(0);
      delay(15);
    }
    game=1;
  }
  if(answer == 2){
    
 tone(kPinSpeaker, NOTE_C4);
 delay(1000);
 tone(kPinSpeaker, NOTE_G4);
 delay(1000);
 tone(kPinSpeaker, NOTE_F4);
 delay(250);
 tone(kPinSpeaker, NOTE_E4);
 delay(250);
 tone(kPinSpeaker, NOTE_D4);
 delay(250);
 tone(kPinSpeaker, NOTE_C5);
 delay(1000);
 tone(kPinSpeaker, NOTE_G4);
 delay(500);
 tone(kPinSpeaker, NOTE_F4);
 delay(250);
 tone(kPinSpeaker, NOTE_E4);
 delay(250);
 tone(kPinSpeaker, NOTE_D4);
 delay(250);
 tone(kPinSpeaker, NOTE_C5);
 delay(1000);
 tone(kPinSpeaker, NOTE_G4);
 delay(500);
 tone(kPinSpeaker, NOTE_F4);
 delay(250);
 tone(kPinSpeaker, NOTE_E4);
 delay(250);
 tone(kPinSpeaker, NOTE_F4);
 delay(250);
 tone(kPinSpeaker, NOTE_D4);
 delay(2000);
  
 noTone(kPinSpeaker);
 answer=0;
  }
}

  
