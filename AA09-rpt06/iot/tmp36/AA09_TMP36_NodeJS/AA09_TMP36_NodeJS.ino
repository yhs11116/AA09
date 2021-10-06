//
// AA00, TMP36 sensor
//

#define TEMP_INPUT 0
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   //getting the voltage reading from the temperature sensor
  int value = analogRead(TEMP_INPUT);

  float voltage = value * 5.0 * 1000;  // in mV
  voltage /= 1023.0; 
   


  float temperatureC = (voltage - 500) / 10 ;  
  Serial.println(temperatureC); 


  delay(1000);
}
