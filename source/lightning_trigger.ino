#include <multiCameraIrControl.h> 

int shutterPin = 13; 
int triggerPin = 0;
int threshold = 10;
int savedLightningValue = 0;
int currentLightningValue = 0;
int delayBetweenShots = 1000;
 
Nikon shutter(shutterPin);

void setup() {
  Serial.begin(9600);
  pinMode(shutterPin, OUTPUT);
  digitalWrite(shutterPin, LOW);
  savedLightningValue = currentLightningValue = analogRead(triggerPin);
}

void loop() {
  currentLightningValue = analogRead(triggerPin);
  Serial.println(savedLightningValue, DEC);
    
  if((currentLightningValue - savedLightningValue) > threshold) {
    Serial.println("Triggering shutter");
    shutter.shutterNow();
    delay(delayBetweenShots);
  }
  
  savedLightningValue = currentLightningValue;
}
