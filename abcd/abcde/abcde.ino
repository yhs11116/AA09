#include "DHT.h"
#define CDS_INPUT 1
#define DHTPIN 2    
#define DHTTYPE DHT22  
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);  
  dht.begin();
}
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
  
  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(lux);   
    
  
  delay(1000);
}

     
//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10.0;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
