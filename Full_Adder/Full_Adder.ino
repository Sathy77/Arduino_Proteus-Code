int A, B, C;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);

}

void loop() {
  A = digitalRead(10);
  A = digitalRead(9);
  A = digitalRead(8);
  int S, Carry;
  S = A ^ B ^ C;
  Carry = ((A & B) | (B & C) | (A & C));
  digitalWrite(13, S);
  digitalWrite(12, Carry);
}
