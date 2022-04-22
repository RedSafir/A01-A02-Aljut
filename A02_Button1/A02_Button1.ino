const int btn = 2;
const int led1 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(btn,INPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(led1));
  if (digitalRead(btn) ==0 )
  {
    do
    {}
    while (digitalRead(btn) ==0);

    digitalWrite(led1, !digitalRead(led1));
    delay(20);
  }

}
