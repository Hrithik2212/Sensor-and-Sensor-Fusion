#define BLYNK_PRINT.serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleESP8266.h>

#define relay1 5
#define relay2 2
#define relay3 0
#define relay4 14

#define BLYNK_AUTH_TOKEN ""

char auth[]=BLYNK_AUTH_TOKEN;
char ssid[]="";
char pass[]="";

BLYNK_WRITE(V0){
    bool value1 = param.asInt();
    if (value1==1){
        digitalWrite(relay1,LOW);
    }
    else{
        digitalWrite(relay1,HIGH);
    }
}

BLYNK_WRITE(V1){
    bool value2 = param.asInt();
    if (value2==1){
        digitalWrite(relay2,LOW);
    }
    else{
        digitalWrite(relay2,HIGH);
    }
}

BLYNK_WRITE(V2){
    bool value1 = param.asInt();
    if (value1==1){
        digitalWrite(relay3,LOW);
    }
    else{
        digitalWrite(relay3,HIGH);
    }
}

BLYNK_WRITE(V3){
    bool value1 = param.asInt();
    if (value1==1){
        digitalWrite(relay4,LOW);
    }
    else{
        digitalWrite(relay4,HIGH);
    }
}

void setup(){
    pinMode(relay1,OUTPUT);
    pinMode(relay2,OUTPUT);
    pinMode(relay3,OUTPUT);
    pinMode(relay4,OUTPUT);

    digitWrite(relay1,HIGH);
    digitWrite(relay2,HIGH);
    digitWrite(relay3,HIGH);
    digitWrite(relay4,HIGH);

    Blynk.begin(auth,ssid,pass,"blynk.cloud",80);
}

void loop(){
    Blynk.begin();
}