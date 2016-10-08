#include <Servo.h>

const int ledPin = 13; 


Servo monServo;

void setup() {
   pinMode(ledPin, OUTPUT);
   monServo.attach(9); 
}

void loop() {
  
  monServo.write(0);
   delay(2000);  // wait 5 seconds before you do it again
  
  monServo.write(180);
  delay(2000);  // wait 5 seconds before you do it again
  monServo.write(0);

}
