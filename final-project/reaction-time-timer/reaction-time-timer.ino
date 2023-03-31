int led = 3;
int incomingByte;
int button = 2;
//int startButton = 6;
int starttime;
int endtime;
int reactiontime;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  //pinMode(startButton, INPUT);
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), endtimer, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
   incomingByte = Serial.read();
   //int buttonState = digitalRead(button);

  // if(buttonState == 1) {
  //   starttime = millis();
  //   digitalWrite(led, HIGH);
  // }

  if(incomingByte == 'S') {
    starttime = millis();
    digitalWrite(led, HIGH);
  }

}

void endtimer() {
  digitalWrite(led, LOW);
  endtime = millis();
  reactiontime = endtime - starttime;
  Serial.println("TIME");
  Serial.println(reactiontime);

}