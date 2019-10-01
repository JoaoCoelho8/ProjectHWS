#include <Servo.h>
Servo myServo;

int red=7;
int blue=8;
int sonar=3;
int opt=0;
int duration_s=0;
int duration_o=0;
int in=0;
int out=0;
int count=0;


void setup() {
  Serial.begin(9600);
  myServo.attach(5);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(sonar, INPUT);
  pinMode(opt, INPUT);
}

void loop() {
  float sonarAverage=0.0;
  int i;
  for (i=0;i<20;i++){
    sonarAverage+=pulseIn(sonar,HIGH);
  }
  sonarAverage/=20;
  duration_s=sonarAverage;
  duration_s= (duration_s/147)*2,54;
  //Serial.println(duration_s);
  if(duration_s<20){
    digitalWrite(blue, HIGH);
    if(in==0){
      out=1;
      myServo.write(0);
    }else{
      myServo.write(90);
      count++;
      in=0;
    }
  }else{
    digitalWrite(blue, LOW);
  }
  
  duration_o=analogRead(opt);
  if(duration_o>266){
    digitalWrite(red, HIGH);
    if(out==0){
      in=1;
      myServo.write(180);
    }else{
      myServo.write(90);
      count--;
      out=0;
    }
  }else{
    digitalWrite(red, LOW);
  }

  Serial.println(count);
}