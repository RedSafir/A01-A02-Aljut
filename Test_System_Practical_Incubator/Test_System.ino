
//Initiation for DHT22
#include "DHT.h"
#define DHTPIN 4 //pin
#define DHTTYPE DHT22 
//............

const int pinRelay[] = {16,5};

DHT dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(115200);
  dht.begin();

  //initiation pin rellay
  for(int i = 0;i< 2; i++)
  {
    pinMode(pinRelay[i],OUTPUT);
  }
  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

  if(t < 25)
  {
    relay(0, true);
    relay(1, false);
    Serial.println("lampu nyala");
  }
  if(t > 27) //ntr diganti jadi 32 lagi
  {
    relay(1, true);
    relay(0, false);
    Serial.println("van nyala");
  }
  if(t>25 && t<27)
  {
    relay(1, false);
    relay(0, false);
    Serial.println("lampu dan van mati");
  }
  
}

void relay(int r, bool y)
{
  if (y == true)
  {
    digitalWrite(pinRelay[r], HIGH);
//    delay(2000);
//    return;
  }
  else
  {
    digitalWrite(pinRelay[r], LOW); 
//    delay(2000);
//    return;
  }
}

//  // Compute heat index in Fahrenheit (the default)
//  float hif = dht.computeHeatIndex(f, h);
//  // Compute heat index in Celsius (isFahreheit = false)
//  float hic = dht.computeHeatIndex(t, h, false);

//  Serial.print(F("Humidity: "));
//  Serial.print(h);
//  Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
