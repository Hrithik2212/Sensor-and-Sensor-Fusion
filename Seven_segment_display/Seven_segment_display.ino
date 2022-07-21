#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {}; 
  byte segmentPins[] ={9,8,7,6,5,4,3,2,1,0};
  byte display_type = COMMON_CATHODE;
  bool resistoronSegments  = true ;
  sevseg.begin(display_type,numDigits,digitPins,segmentPins,resistoronSegments);
  sevseg.setBrightness(90);
}

void loop() {
  for(int i=0;i<=10;i++){
    if (i==10){
      i=0; 
    }
    sevseg.setNumber(i);
    sevseg.refreshDisplay();
    delay(1000);
  }
}
