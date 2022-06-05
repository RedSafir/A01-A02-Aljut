const int pin[] = {6,7,8,9,13,12,11,10};
const int mic = A0;
const int led1 = 2;
const int led2 = 3;
byte hasil;

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
  if(hasil > 10)
  {
    Serial.println(hasil);
  
  }
//    Serial.println(hasil);
//============deteksi suara kecil
  if (hasil < 100)
  {
    kanan();
  }

//=============deteksi suara besar
  if (hasil > 100 || digitalRead(led1) == 1) 
  {
    kiri();
  }
}

void kanan()
{
       for(int i=0; i<=7; i++)
          {
            if (analogRead(mic) > 5 )
            {
              break;
            }
            digitalWrite(pin[i], HIGH);
            delay(250);
            digitalWrite(pin[i], LOW);
          }
          digitalRead(led1) == 1;
}

void kiri()
{
        for(int i=7; i>=0; i--)
      {
        digitalWrite(pin[i],HIGH);
        delay(250);
        digitalWrite(pin[i], LOW);
      } 
}
