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
    Serial.println(" kiri");
    digitalWrite(pin[i],HIGH);
    delay(d);

    digitalWrite(pin[i],LOW);
    delay(d);
    cetak(i,pin[i]);
  }
}

void putarKanan()
{
   for(i=7;i>=0;i--)
  {
    Serial.println(" kanan");
    digitalWrite(pin[i],HIGH);
    delay(d);

    digitalWrite(pin[i],LOW);
    delay(d);
    cetak(i,pin[i]);
  }
}

void cetak(int a, int b)
{
  Serial.print(a);
  Serial.print(" X ");
  Serial.print(b); 
  Serial.print(" = ");
  Serial.print(a_X_b(a,b));
}

int a_X_b(int a,int b)
{
  int hasil;
  hasil = a * b;
  return hasil;
}
