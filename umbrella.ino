/*
  Yún HTTP Client

 This example for the YunShield/Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>
#include <Servo.h>

String res = "";
Servo monServo;

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  SerialUSB.begin(9600);
   monServo.attach(9); 

  while (!SerialUSB); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://mathemagie.net/asciilogo.txt");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    res = res + c;
 
  }
   SerialUSB.print(res.substring(0,3));
   if (res.substring(0,3) == "cou") {
    SerialUSB.print("yes");
    digitalWrite(13, LOW);
    monServo.write(10);
    
   }else {
     monServo.write(90);
   }
   res = "";
  
  SerialUSB.flush();

  delay(2000);
}
