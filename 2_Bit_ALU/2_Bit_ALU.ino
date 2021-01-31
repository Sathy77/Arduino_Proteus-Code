int S0, S1, S2;
int S[2], COUT;
int A[2], B[2];
void setup() {
  Serial.begin(9600);

  //SWITCH
  pinMode(5, INPUT); //S0
  pinMode(4, INPUT); //S1
  pinMode(3, INPUT); //S2

  //INPUT
  pinMode(7, INPUT); //A[0]
  pinMode(6, INPUT); //A[1]
  pinMode(9, INPUT); //B[0]
  pinMode(8, INPUT); //B[1]

  //OUTPUT
  pinMode(10, OUTPUT); //S[0]
  pinMode(11, OUTPUT); //S[1]
  pinMode(12, OUTPUT); //COUT
}

void loop() {
  S0 = digitalRead(5);
  S1 = digitalRead(4);
  S2 = digitalRead(3);

  A[0] = digitalRead(7);
  A[1] = digitalRead(6);
  B[0] = digitalRead(9);
  B[1] = digitalRead(8);

  //S2 S1 S0
  if (S2 == LOW && S1 == LOW && S0 == LOW)
  {
    //A+B
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == LOW && S1 == LOW && S0 == HIGH)
  {
    //A-B
    NOT(B);
    ADD_1(B);
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == LOW)
  {
    //A-1
    B[0] = HIGH;
    B[1] = HIGH;
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, LOW);
  }
  else if (S2 == LOW && S1 == HIGH && S0 == HIGH)
  {
    //A+1
    B[0] = HIGH;
    B[1] = LOW;
    FULLADDER();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == LOW)
  {
    //A AND B
    AND();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == LOW && S0 == HIGH)
  {
    //A OR B
    OR();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
  else if (S2 == HIGH && S1 == HIGH && S0 == LOW)
  {
    // NOT A
    NOT(A);
    digitalWrite(10, A[0]);
    digitalWrite(11, A[1]);
    digitalWrite(12, COUT);

  }
  else if (S2 == HIGH && S1 == HIGH && S0 == HIGH)
  {
    // A XOR B
    XOR();
    digitalWrite(10, S[0]);
    digitalWrite(11, S[1]);
    digitalWrite(12, COUT);
  }
}

void FULLADDER()
{
  COUT = LOW;
  for (int i = 0; i <= 1; i++)
  {
    int COUNT = 0;
    if (A[i] == HIGH)
    {
      COUNT = COUNT + 1;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (COUT == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (COUT == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (COUT == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (COUT == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    else if (A[i] == LOW)
    {
      COUNT = COUNT + 0;
      if (B[i] == HIGH)
      {
        COUNT = COUNT + 1;
        if (COUT == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (COUT == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
      else if (B[i] == LOW)
      {
        COUNT = COUNT + 0;
        if (COUT == HIGH)
        {
          COUNT = COUNT + 1;
        }
        else if (COUT == LOW)
        {
          COUNT = COUNT + 0;
        }
      }
    }
    if (COUNT == 3)
    {
      S[i] = HIGH;
      COUT = HIGH;
    }
    else if (COUNT == 2)
    {
      S[i] = LOW;
      COUT = HIGH;
    }
    else if (COUNT == 1)
    {
      S[i] = HIGH;
      COUT = LOW;
    }
    else if (COUNT == 0)
    {
      S[i] = LOW;
      COUT = LOW;
    }
  }
}

void ADD_1(int *X)
{
  if (*(X + 0) == HIGH)
  {
    //Carry=1
    *(X + 0) = LOW;
    if (*(X + 1) == HIGH)
    {
      *(X + 1) = LOW;
      COUT = HIGH;
    }
    else if (*(X + 1) == LOW)
    {
      *(X + 1) = HIGH;
      COUT = LOW;
    }
  }
  else if (*(X + 0) == LOW)
  {
    //Carry=0
    *(X + 0) = HIGH;
    if (*(X + 1) == HIGH)
    {
      *(X + 1) = HIGH;
      COUT = LOW;
    }
    else if (*(X + 1) == LOW)
    {
      *(X + 1) = LOW;
      COUT = LOW;
    }
  }
}

void NOT(int *X)
{
  if (*(X + 0) == LOW && *(X + 1) == LOW)
  {
    *(X + 0) = HIGH;
    *(X + 1) = HIGH;
  }
  else if (*(X + 0) == LOW && *(X + 1) == HIGH)
  {
    *(X + 0) = HIGH;
    *(X + 1) = LOW;
  }
  else if (*(X + 0) == HIGH && *(X + 1) == LOW)
  {
    *(X + 0) = LOW;
    *(X + 1) = HIGH;
  }
  else if (*(X + 0) == HIGH && *(X + 1) == HIGH)
  {
    *(X + 0) = LOW;
    *(X + 1) = LOW;
  }
  COUT = LOW;
}

void AND()
{
  for (int i = 0; i <= 1; i++)
  {
    if (A[i] == HIGH && B[i] == HIGH)
    {
      S[i] = HIGH;
    }
    else
    {
      S[i] = LOW;
    }
  }
  COUT = LOW;
}

void OR()
{
  for (int i = 0; i <= 1; i++)
  {
    if (A[i] == LOW && B[i] == LOW)
    {
      S[i] = LOW;
    }
    else
    {
      S[i] = HIGH;
    }
  }
  COUT = LOW;
}

void XOR()
{
  for (int i = 0; i <= 1; i++)
  {
    if ((A[i] == LOW && B[i] == LOW) || (A[i] == HIGH && B[i] == HIGH))
    {
      S[i] = LOW;
    }
    else
    {
      S[i] = HIGH;
    }
  }
  COUT = LOW;
}

