int d = 250;
int i;

void setup() 
{
  Serial.begin(9600);
  i = 13;

  while(i>5)
  {
    pinMode(i,OUTPUT);
    i = i - 1;
  }
  i = 13;
}

void loop() 
{
  while( i>5)
  {
    digitalWrite(i,HIGH);
    delay(d);

    digitalWrite(i,LOW);
    delay(d);
    i--;
  }

  i=13;
}
