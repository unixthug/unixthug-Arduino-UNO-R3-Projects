//Adam Jones || 12-26-2023 || We Wish You A Merry Christmas! (Arduino Ver.)

//vars
const int buzz = 9;
int button, buttonVal, led;

//runs once at startup
void setup() {
  button = 2;
  led = 7;
  pinMode(buzz, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

//frequency of musical notes
int note[] = {
  260, 347, 347, 390, 347, 328, 292, 292, 292,
  390, 390, 437, 390, 347, 328, 260, 260,
  437, 437, 463, 437, 390, 347, 292, 260, 260,
  292, 390, 328, 347
};

//duration of notes || 1000 / note division
int duration[] = {
  250, 250, 125, 125, 125, 125, 250, 250, 250,
  250, 125, 125, 125, 125, 250, 250, 250,
  250, 125, 125, 125, 125, 250, 250, 125, 125,
  250, 250, 250, 500
};

//plays a tone using the note for frcequency and duration for .. :D
void Song() {
  digitalWrite(led, HIGH);
  for (int i = 0; i < sizeof(note)/sizeof(*note); i++) {
    tone(buzz, note[i], duration[i]);
    delay(duration[i] * 1.3);
  }
  digitalWrite(led, LOW);
}

//boolean triggered by button press
bool play = false;

//runs coninuously
void loop() {
  buttonVal = digitalRead(button);
  if (buttonVal == HIGH) {
    play = true;
  }
  if (play == true) {
    play = false;
    Song();
    noTone(buzz);
  }
}
