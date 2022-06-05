const int pin[] = {6,7,8,9,13,12,11,10};
const int mic = A0;
const int led1 = 2;
const int led2 = 3;
byte hasil,hasil2;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i<=7; i++)
  {
    pinMode(pin[i],OUTPUT);
  }
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(mic,INPUT);
}

void loop() {
  hasil = analogRead(mic);
//  if(hasil > 50)
//  {
//    Serial.println("terdeteksi");
//  
//  }
   Serial.println(hasil);
   
//============deteksi suara kecil
  if (hasil > 5 && hasil < 200)
  {
    digitalWrite(led1,! digitalRead(led1));
    delay(10);
    digitalWrite(led2, LOW);
  }
///------------- LED muter kanan => kiri
  if(digitalRead(led1) == 1)
  {
     for(int i=0; i<=7; i++)
          {
            if (analogRead(mic) > 10)
            {
              break;
            }
            digitalWrite(pin[i], HIGH);
            delay(250);
            digitalWrite(pin[i], LOW);
          }
  }

//=============deteksi suara besar
  if (hasil > 200) 
  {
    digitalWrite(led2,! digitalRead(led2));
    digitalWrite(led1, LOW); 
  }

///------------LED muter ke kiri=> kanan
   if (digitalRead(led2) == 1)
    {
      for(int i=7; i>=0; i--)
      {
        if (analogRead(mic) >10 )
            {
              break;
            }
        digitalWrite(pin[i],HIGH);
        delay(250);
        digitalWrite(pin[i], LOW);
      }
    }
//  Serial.print(digitalRead(led1));
//  Serial.print(" - ");
//  Serial.println(digitalRead(led2) );

}
