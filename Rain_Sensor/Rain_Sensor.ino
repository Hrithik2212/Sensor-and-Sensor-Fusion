#define BUZZER_PIN 3

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  Serial.println("Setting Up in Progress");
  delay(5000);
  Serial.println("Done");
}

void loop() {
  int SensorValue = analogRead(A0);
  Serial.print("Sensor Value =");
  Serial.println(SensorValue);
  if (SensorValue <1000){
    digitalWrite(BUZZER_PIN,HIGH);
    Serial.println("Rain Detected");
  }
  else{
    digitalWrite(BUZZER_PIN,LOW);
    Serial.println("Rain not detected"); 
  }
  delay(1000);
}
