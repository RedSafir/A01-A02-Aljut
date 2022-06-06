const int btn1 = 5;
const int btn2 = 4;
const int led1 = 3;
const int led2 = 2;
const int lEd[] = {6,11,8,13,9,12,7,10}; //lampu zigzag
const int lEd2[] = {6,7,8,9,13,12,11,10}; //lampu arah jam
const int lEd3[] = {6,7,10,11,8,9,12,13}; //kedip kanan kiri
int i;

void setup() {
  Serial.begin(9600);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT); 
   
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT); 

  for(int i = 0; i<=7; i++)
  {
    pinMode(lEd[i],OUTPUT);//inisiasi lampu zigzag
    pinMode(lEd2[i],OUTPUT);//inisiasi lampu arah jam
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
          kiriKananJam();
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
//          zigzag();
            kedipKananKiri();
        }

  if(digitalRead(led1) == 1 ||  digitalRead(led2) == 1)
  {
  Serial.print(digitalRead(led1));
  Serial.print(" - ");
  Serial.println(digitalRead(led2) );
  }
}

void zigzag() //muter zigzag
{
  for(int i=0; i<=7; i++)
  {
  if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
  {
    break;
  }
  digitalWrite(lEd[i], ! digitalRead(lEd[i]));
  delay(250);
  digitalWrite(lEd[i], LOW);
  }
}

void kiriKananJam() //muter arah jam
{
  i = 7;
  do
  {
      if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
       {
          break;
       }
    digitalWrite(lEd2[i],! digitalRead(lEd2[i]));
    delay(250);
    digitalWrite(lEd2[i], LOW);
    i = i - 1;
      
  }while(i>=0);
}

void kedipKananKiri() //kedip 4 led kanan 3x lalu 4 led kiri 3x
{
  int p = 0;
  do
  {
       if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
       {
          break;
       }
    digitalWrite(lEd3[0],!digitalRead(lEd3[0]));
    digitalWrite(lEd3[1],!digitalRead(lEd3[1]));
    digitalWrite(lEd3[2],!digitalRead(lEd3[2]));
    digitalWrite(lEd3[3],!digitalRead(lEd3[3]));

    delay(250);

    digitalWrite(lEd3[0],LOW);
    digitalWrite(lEd3[1],LOW);
    digitalWrite(lEd3[2],LOW);
    digitalWrite(lEd3[3],LOW);
    
    delay(250);
    p = p + 1;
    Serial.print("kanan "); Serial.println(p);
    
  }while(p < 3);

  p = 0;
  
  do
  {
       if(digitalRead(btn2)==0 || digitalRead(btn1)==0)
       {
          break;
       }
    digitalWrite(lEd3[4],!digitalRead(lEd3[4]));
    digitalWrite(lEd3[5],!digitalRead(lEd3[5]));
    digitalWrite(lEd3[6],!digitalRead(lEd3[6]));;
    digitalWrite(lEd3[7],!digitalRead(lEd3[7]));

    delay(250);

    digitalWrite(lEd3[4],LOW);
    digitalWrite(lEd3[5],LOW);
    digitalWrite(lEd3[6],LOW);
    digitalWrite(lEd3[7],LOW);

    delay(250);
    p = p + 1;
    
    Serial.print("kiri "); Serial.println(p);
  }while(p < 3);
}
