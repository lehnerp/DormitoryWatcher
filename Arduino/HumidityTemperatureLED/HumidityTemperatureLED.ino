#include "DHT.h"

#define DHTPIN 8 
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

int BlueLED = 11;
int GreenLED = 10 ;
int RedLED = 9;

void setup() {
  pinMode (BlueLED, OUTPUT);
  pinMode (GreenLED, OUTPUT);
  pinMode (RedLED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F(" C "));
  Serial.println();

  if(h > 80){
    analogWrite(RedLED, 50);
    analogWrite(GreenLED, 0);
  }
  else{
    analogWrite(RedLED, 0);
    analogWrite(GreenLED, 50);
  }

}
