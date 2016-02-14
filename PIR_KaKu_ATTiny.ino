#include <NewRemoteTransmitter.h>

NewRemoteTransmitter transmitter(123, 3, 260, 2);
int LED = 4;
const int PIRpin = 2;
int PIRstate = 0, PIRprevState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIRpin, INPUT);
  delay(10000);
  pinMode(LED, OUTPUT);
  Blink_LED();
}

void loop() {
  
  interrupts();
  PIRstate = digitalRead(PIRpin);
  //Serial.println(PIRstate);

  if (PIRstate == 1){
    if (PIRprevState == 0){
      transmitter.sendUnit(1, true);
      analogWrite(LED, 255);
      PIRprevState = 1;  
    }
    else{
      transmitter.sendUnit(1, true);
      analogWrite(LED, 255);
      delay(8000);
    }
  }
    else {
      if (PIRprevState == 1){
      transmitter.sendUnit(1, false);
      analogWrite(LED, 0);
      PIRprevState = 0;
      }
    }
  delay(250);
}

void Blink_LED(){
  analogWrite(LED, 255);
  delay(200);
  analogWrite(LED, 0);
  delay(200);
  analogWrite(LED, 255);
  delay(200);
  analogWrite(LED, 0);
}
