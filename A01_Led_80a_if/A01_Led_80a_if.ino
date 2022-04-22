int d = 250;
int i;

void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  i = 13;
}

void loop()
{
  Serial.println(i);
  digitalWrite(i,HIGH);
  delay(d);

  digitalWrite(i,LOW);
  delay(d);

  if (i<7)
  {
    i = 14;
  }
  i--;
}
