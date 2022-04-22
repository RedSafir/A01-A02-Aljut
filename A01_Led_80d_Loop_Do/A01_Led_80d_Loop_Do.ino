int d = 250;
int i;

void setup() 
{
  Serial.begin(9600);
  i = 13;
  do
  {
    pinMode(i,OUTPUT);
    i--;
  }while(i>=6);

  i = 13;
}

void loop() 
{
  do
  {
  Serial.println(i);

  digitalWrite(i,HIGH);
  delay(d);

  digitalWrite(i,LOW);
  delay(d);
  i--;

  }while(i>5);

  i = 13;
  

}
