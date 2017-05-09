int detOne = 2;
int detTwo = 3;
int detThree = 4;
int detFour = 5;
int PIR = 6;
int on = 13;
float capOne;
float capTwo;
float capThree;
float capFour;
int beat = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode (PIR, INPUT);
  pinMode (detOne, OUTPUT);
  pinMode (detTwo, OUTPUT);
  pinMode (detThree, OUTPUT);
  pinMode (detFour, OUTPUT);
  pinMode (on, OUTPUT);
  digitalWrite (PIR, LOW);
  delay(10000);
  digitalWrite (on, HIGH);
}

void loop()
{
  
  int one = analogRead (A0);
  int two = analogRead (A1);
  int thr = analogRead (A2);
  int fou = analogRead (A3);
  
  capOne = one * (5.0 / 1023.0);  
  capTwo = two * (5.0 / 1023.0);
  capThree = thr * (5.0 / 1023.0);
  capFour = fou * (5.0 / 1023.0);
  
  //capOne = 50mV
  if (capOne > 4.0)
  {
    digitalWrite (detOne, HIGH);
  }
  else
  {
    digitalWrite (detOne, LOW);
  }
  
  //capTwo = 5V
  Serial.println(beat);
  if (capTwo < 2.0)
  {
    digitalWrite (detTwo, HIGH);
  }
  else
  {
    digitalWrite (detTwo, LOW);
  }
  
  if (capFour == 0)
  {
    beat = 1;
  }
  else
  {
    beat = 0;
  }
  
  if ((beat == 0) && (capFour > 4.0))
  {
    digitalWrite(detThree, HIGH);
  }
  else
  {
    digitalWrite (detThree, LOW);
  }
  
  if ((beat == 0) && ((capThree > 4.0) || (capThree < 0.15)))
  {
    digitalWrite (detFour, HIGH);
  }
  else
  {
    digitalWrite (detFour, LOW);
  }
  
  if (digitalRead(PIR) == HIGH)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite (i, HIGH);
    }
    delay (10000);
    for (int i = 2; i < 6; i++)
    {
      digitalWrite (i, LOW);
    }
  }
  
}
