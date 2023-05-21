/*

 * This is the Arduino code for LE18-D80NK Infrared Obstacle Avoidance Sensor
This code is to use E18-D80NK Infrared Sensor to detect obstacle and trigger an
event like starting or stopping motor or servo or relay or anything else.


 *  *
 // Writeen by Ahmad S. for Robojax.com on
// on Feb 22, 2018 at 20:50 om  city of Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 *
 * watch LE18-D80NK  video for details https://youtu.be/MrYsmAwzfrM
 * Code is available at http://robojax.com/learn/arduino
the Wiring:
Brown: 5V DC
Blue:  GNG
Black: Signal, to PIN 2




 *

*/

#define SENSOR 2 // define pint 2 for sensor
#define BUZZER 8 // define pin 9 as for ACTION
#include <Servo.h>
#include<string.h>
Servo gate;
String status = "Not-Verified";
/*
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 *
 */

void setup()
{
  // E18-D80NK Obstacle Sensor Code by Robojax.com 2018022
  Serial.begin(9600);            // setup Serial Monitor to display information
  pinMode(SENSOR, INPUT_PULLUP); // define pin as Input  sensor
  pinMode(BUZZER, OUTPUT);// define pin as OUTPUT for ACTION
  gate.attach(9);
 
}

void loop()
{
  // E18-D80NK Obstacle Sensor Code by Robojax.com 2018022
  int L = digitalRead(SENSOR); // read the sensor

  if (L == 0)
  {
    Serial.println(1);
    delay(2000);    
    status =  Serial.readString();
    if (status == "verified")
    {
      gate.write(90);
    }
    else{
      digitalWrite(BUZZER,HIGH);// send singal
    }
  }
  else
  {

    Serial.println(0);
    digitalWrite(BUZZER,LOW);// turn the relay OFF
    gate.write(0);
  }

  delay(500);
  // E18-D80NK Obstacle Sensor Code by Robojax.com 2018022
}


