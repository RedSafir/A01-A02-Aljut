const int btn1 = 5;
const int btn2 = 4;
const int led1 = 3;
const int led2 = 2;
const int lEd[] = {6,7,8,9,13,12,11,10};

void setup() {
  Serial.begin(9600);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT); 
   
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT); 

  for(int i = 0; i<=7; i++)
  {
    pinMode(lEd[i],OUTPUT);
  }
}

void loop() {
///----------------------- tombol 1
        if (digitalRead(btn1)==0) {
          do
          { }
          while (digitalRead(btn1)==0);
          digitalWrite(led1, ! digitalRead(led1));
          digitalWrite(led2, LOW);
        delay(20);
      }
///------------- LED muter kanan => kiri
  if(digitalRead(led1) == 1)
  {
     for(int i=0; i<=7; i++)
          {
            if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
            {
              break;
            }
            digitalWrite(lEd[i], ! digitalRead(lEd[i]));
            delay(1250);
            digitalWrite(lEd[i], LOW);
          }
  }
///----------------------- tombol 2 
      if (digitalRead(btn2)==0)
  {
      do
      { }
      while (digitalRead(btn2)==0);
      digitalWrite(led2,! digitalRead(led2));
      digitalWrite(led1,LOW);
    delay(20);
  } 
///------------LED muter ke kiri=> kanan
       if (digitalRead(led2) == 1)
        {
          for(int i=7; i>=0; i--)
           {
            if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
            {
              break;
            }
            digitalWrite(lEd[i],! digitalRead(lEd[i]));
            delay(1250);
            digitalWrite(lEd[i], LOW);
           }
        }

  if(digitalRead(led1) == 1 ||  digitalRead(led2) == 1)
  {
  Serial.print(digitalRead(led1));
  Serial.print(" - ");
  Serial.println(digitalRead(led2) );
  }
}
