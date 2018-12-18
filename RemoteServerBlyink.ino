/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Rotate a servo using a slider!

  App project setup:
    Slider widget (0...180) on V3
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "3bbf11e446bd472cbfb88c33220e8c8a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DIR Makeistan";
char pass[] = "makershaker";

Servo servo;

BLYNK_WRITE(V0)
{
  for (int i = 0; i< 45; i++){
    servo.write(i);
    delay(20);
  }

  for (int i = 45; i >= 0; i--){
    servo.write(i);
    delay(20);
  }
  Serial.println("Hello");
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  servo.attach(D0);
  servo.write(0);
}
void loop()
{
  Blynk.run();
}
