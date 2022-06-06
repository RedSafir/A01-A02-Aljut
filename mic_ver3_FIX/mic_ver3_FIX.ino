int mic1 = A0;
int pin []={13,12,11,10,6,7,8,9};
byte hasil;
int i = 0;


void setup() {
  for (int t=0; t<=7; t++) {
    pinMode(pin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  hasil = analogRead(mic1);
//  delay(250);
//  hasil2 = analogRead(mic1);
  Serial.println(hasil);

  if(hasil = analogRead(mic1); hasil < 15 || hasil > 20)
  {
    i = i + 1;
    Serial.println(hasil);
  }else{
//    Serial.println("else 1");
    Serial.println(i);
  }
  
  switch (i)
  {
    case 0:
      Serial.println("mati 1");
      break;
    case 1:
    {
      Serial.println("Kanan");
      for (int r=0; r<8; r++) 
      {
        digitalWrite(pin[r], !digitalRead(pin[r]));
        delay(500);
        digitalWrite(pin[r], LOW);
          if(hasil = analogRead(mic1); hasil < 15 || hasil > 20)
          {
             Serial.println("pindah");
             i = i + 1;
             delay(500);
             break;
          }
      }
    }
    break;
     
    case 2: 
    {
      Serial.println("Kiri");
      for (int t=7; t>=0; t--)
      {
        digitalWrite(pin[t], !digitalRead(pin[t]));
        delay(500);
        digitalWrite(pin[t], LOW);
          if(hasil = analogRead(mic1); hasil < 15 || hasil > 20)
          {
             Serial.println("pindah");
             i = i + 1;
             delay(500);
             break;
          }
      }
    }
    break;
    
    case 3:
    {
      i = 0;
      Serial.println("mati 2");
      Serial.println(i);
      delay(500);
    }
    break;
  }
}
