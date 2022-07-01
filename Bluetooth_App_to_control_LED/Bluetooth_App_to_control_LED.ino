#define LED 13
int state =0;

void setup() {
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()>0){
    state= Serial.read();
    if (state='0'){
      digitalWrite(LED,LOW);
      Serial.println("LED Off");
    }
    else if(state='1'){
      digitalWrite(LED,HIGH);
      Serial.println("LED On");
    }
  }
}
