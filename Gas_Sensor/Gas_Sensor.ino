// Gas Leakage Detection and Indication System Using Arduino 
int LPG = A0;
int LED = 3;
float sensorValue;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(LPG,INPUT);
  Serial.begin(9600);
  Serial.println("Gas Sensor Warming Up");
  delay(5000);
  Serial.println("Done");
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.print("Sensor value = ");
  Serial.println(sensorValue);
  if (sensorValue > 300){
    digitalWrite(LED,HIGH);
    Serial.println("Gas Detected");
  }
  else{
    digitalWrite(LED,LOW);
    Serial.println("Gas Not Detected");
  }
  delay(1000);
}
