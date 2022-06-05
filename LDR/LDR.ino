byte pot = A0;
int led[] = {6,7,8,9,13,12,11,10};
byte hasil;
int i;

void setup()
{
  for(i= 0; i<7; i++)
  {
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  hasil = analogRead(pot);
  Serial.println(hasil);

//=================rata kiri
  if (hasil<200)
  {
     for(int i=0; i<8; i++)
          {
            digitalWrite(led[i], ! digitalRead(led[i]));
            delay(250);
            digitalWrite(led[i], LOW);
          }
  }
  
//===================rata kanan
  if (hasil>200)
  {
   for(int i=7; i>=0; i--)
           {
            digitalWrite(led[i],! digitalRead(led[i]));
            delay(250);
            digitalWrite(led[i], LOW);
           }
  }
        
  
}
