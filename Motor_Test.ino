int reverseSwitch = 2;
int CLOCK1 = 7;
int DIR1 = 6;

int CLOCK2 = 10;
int DIR2 = 9;

int p;
float delay_time = 500;
boolean setdir = LOW; // Set Direction

// Interrupt Handler
void revmotor () {
  setdir = !setdir;
}

void setup() {
  pinMode(CLOCK1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(CLOCK2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
}

void loop() {
  StepForward(delay_time);
  StepForward180(delay_time);

  p = analogRead(A0);
  delay_time = map(p, 0, 1023, 400, 1500);
}

void StepForward(float delay_time)
{
  digitalWrite(DIR1, LOW);
  for (int i = 0; i < 1; i++)
  {
    for (int x = 0; x < 3100 / 50; x++)
    {
      digitalWrite(CLOCK1, HIGH);
      delayMicroseconds(delay_time);
      digitalWrite(CLOCK1, LOW);
      delayMicroseconds(delay_time);
    }
    delay(delay_time);
  }
}

void StepForward180(float delay_time)
{
  digitalWrite(DIR2, LOW);
  for (int i = 0; i < 1; i++)
  {
    for (int x = 0; x < 3100 / 2; x++)
    {
      digitalWrite(CLOCK2, HIGH);
      delayMicroseconds(delay_time);
      digitalWrite(CLOCK2, LOW);
      delayMicroseconds(delay_time);
    }
    delay(delay_time);
  }
  digitalWrite(DIR2, HIGH);
  for (int i = 1; i < 2; i++)
  {
    for (int x = 0; x < 3100 / 2; x++)
    {
      digitalWrite(CLOCK2, HIGH);
      delayMicroseconds(delay_time);
      digitalWrite(CLOCK2, LOW);
      delayMicroseconds(delay_time);
    }
    delay(delay_time);
  }
}
