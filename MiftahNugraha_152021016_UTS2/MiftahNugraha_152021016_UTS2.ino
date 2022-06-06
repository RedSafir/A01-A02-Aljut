byte pot = A0;
int led[] = {6,7,8,9,13,12,11,10};
int led1 = 2;
int led2 = 3;
byte hasil;
int i;

void setup()
{
  for(i= 0; i<7; i++)
  {
    pinMode(led[i],OUTPUT);
  }
  pinMode(led1,OUTPUT);
  pinMode(led2,INPUT);
  Serial.begin(9600);
}

void loop() {
  hasil = analogRead(pot);
  Serial.println(analogRead(pot));

//=============================================
  if (analogRead(pot) > 250 && analogRead(pot)< 500)
  {
    i = 7;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
     while(i>=0)
     {
      digitalWrite(led[i], ! digitalRead(led[i]));
      delay(250);
      digitalWrite(led[i], LOW);
      i = i - 1;
     }
  }
  
//===========================================
  if (analogRead(pot)>500 && analogRead(pot)<750)
  {
     i = 0;
     digitalWrite(led2, HIGH);
     digitalWrite(led1, LOW);
     do
    {
      digitalWrite(led[i],! digitalRead(led[i]));
      delay(250);
      digitalWrite(led[i], LOW);
      i = i +1;
    }while(i<=7);
  }
  
  if(analogRead(pot)<250 || analogRead(pot)>750)
  {
     digitalWrite(led2, LOW);
     digitalWrite(led1, LOW);
  }

}

//     for(int i=0; i<8; i++)
//          {
//            digitalWrite(led[i], ! digitalRead(led[i]));
//            delay(250);
//            digitalWrite(led[i], LOW);
//          }
//   for(int i=7; i>=0; i--)
//           {
//            digitalWrite(led[i],! digitalRead(led[i]));
//            delay(250);
//            digitalWrite(led[i], LOW);
//           }  
