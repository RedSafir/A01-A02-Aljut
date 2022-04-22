int d = 250;
int i;

void setup() 
{
  Serial.begin(9600);
  for(i=6; i<=13; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() 
{
  for(i=13; i>=6; i--)
  {
    Serial.println(i);
    digitalWrite(i,HIGH);
    delay(d);

    digitalWrite(i,LOW);
    delay(d);
  }
}
