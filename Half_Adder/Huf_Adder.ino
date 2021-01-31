int A,B;
void setup() {
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,INPUT);
pinMode(10,INPUT);

}

void loop() {
  A = digitalRead(10); 
  B = digitalRead(11);
  int s,c;

  s=A^B;
  c=A&B;
  digitalWrite(13, s);
  digitalWrite(12, c);
}
