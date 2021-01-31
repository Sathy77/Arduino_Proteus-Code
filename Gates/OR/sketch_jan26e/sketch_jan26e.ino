//OR Gate

int buttonStatus1, buttonStatus2;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);

}

void loop() {
  buttonStatus1 = digitalRead(12);
  buttonStatus2 = digitalRead(11);
  if(buttonStatus1==HIGH || buttonStatus2==HIGH)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}
