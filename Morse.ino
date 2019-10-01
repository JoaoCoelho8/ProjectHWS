int led = 2;
int led = 2;
int button = 3;
int morseAlf = 27;
const char *message= "hello";

static const struct {
  const char letter, *code;
}
MorseMap[] = {
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', ".-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { ' ', "     " },
};

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void flashLed(const char * code) {
  for (int i = 0; i < strlen(code); i++) {
    if (code[i] == '.') {
      digitalWrite(led, HIGH);
      delay(500);
    }
    else if (code[i] == '-') {
      digitalWrite(led, HIGH);
      delay(1500);
    }
    else {
      digitalWrite(led, LOW);
      delay(500);
    }
    digitalWrite(led, LOW);
    delay(2000);
  }
}

void morse(const char * letter) {
  for (int i = 0; i < strlen(letter); i++) {
    char letterMessage = letter[i];
    Serial.println(letterMessage);
    for (int j = 0; j < morseAlf; j++) {
      if (MorseMap[j].letter == letterMessage) {
        flashLed(MorseMap[j].code);
        break;
      }
    }
    delay(2000);
  }
}

void loop() {
  morse(message);
}