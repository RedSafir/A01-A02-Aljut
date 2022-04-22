int d = 250;
int i;
int pin[] = {13,12,11,10,6,7,8,9};

void setup() 
{
  Serial.begin(9600);
  for(i=0; i<=8; i++)
  {
    pinMode(pin[i],OUTPUT);
  }
}

void loop() 
{
 putarKiri();
 putarKanan();
}

void putarKiri()
{
   for(i=0;i<=7;i++)
  {
    digitalWrite(pin[i],HIGH);
    delay(d);

    digitalWrite(pin[i],LOW);
    delay(d);
    Serial.println('kiri');
  }
}

void putarKanan()
{
   for(i=7;i>=0;i--)
  {
    digitalWrite(pin[i],HIGH);
    delay(d);

    digitalWrite(pin[i],LOW);
    delay(d);
    Serial.println('kanan');
  }
}
