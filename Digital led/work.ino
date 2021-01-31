
//My ID is 18101077
int Led[7] = {3, 4, 5, 6, 7, 8, 9};
void setup() {
  for (int i = 0; i <= 6; i++)
  {
    pinMode(Led[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i <= 6; i++)
  {
    digitalWrite(Led[i], HIGH);
    delay(100);
    digitalWrite(Led[i], LOW);
    delay(100);
  }
}
