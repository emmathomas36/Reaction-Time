int button = 3;
int sound = 6;
int led = 2;
//volatile int state = LOW;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(button, INPUT);
  //attachInterrupt(digitalPinToInterrupt(button), starter, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(button);
  if(buttonState == 1) {
      Serial.println("START");
      digitalWrite(led, HIGH);
      delay(400);
      digitalWrite(led, LOW);
  }
    
}

// void starter() {
//   // send to python
//   Serial.println("in starter");
  
// }
