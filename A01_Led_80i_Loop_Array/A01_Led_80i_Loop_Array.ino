int pin[] ={13,8,11,6,9,12,7,10};
const int d = 1000;

void setup()
{
  Serial.begin(9600);
  
  for (int i=0;i<8;i++)
  {
    pinMode(pin[i],OUTPUT);
  }

}

void loop()
{
 for (int i=0; i<8;i++)
 {
  Serial.println(pin[i]);
  digitalWrite(pin[i],HIGH);
  delay(d);
  digitalWrite(pin[i],LOW);
 }
}
