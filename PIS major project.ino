#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>

TMRpcm tmrpcm;
int buttonState1 = 0 ;
int buttonState2 = 0;
int buttonState3 = 0;

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {

return;
}
tmrpcm.quality(1);
tmrpcm.setVolume(5);
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
}

void loop(){ 
  delay(2000);
  buttonState1 = digitalRead(5);
  buttonState2 = digitalRead(6);
  buttonState3 = digitalRead(7);
  if(buttonState1==HIGH)
  {
    Serial.print("1");
    tmrpcm.play("1.wav");
  }
  else if(buttonState2==HIGH)
  {
    Serial.print("2");
    tmrpcm.play("2.wav");
  }
  else if(buttonState3==HIGH)
  {
    Serial.print("3");    
    tmrpcm.play("3.wav");
  }
  }
