#include <Stepper.h>
#include <Servo.h>
#include "Arduino.h"
#include "Motors.h"

/*Stepper stepper1 = Stepper(200, 53, 52, 51, 50); // X-Axis
Stepper stepper2 = Stepper(200, 49, 48, 47, 46); // Y-Axis
Stepper stepper3 = Stepper(200, 45, 44, 43, 42); // Z1-Axis
Stepper stepper4 = Stepper(200, 41, 40, 39, 38); // Z2-Axis*/
pinMode(A0,INPUT);
double reading=0;
int signal=0;

motors something;

void setup() {

  
  //////////////////////////////////
int safeHeight=0;
int zero=0;
for (int x=0; x<15;x++)
{
for (int y=0; y<16;y++)
{
  motors::goHere(x,y,safeDistance,zero);
  delay(250);
  reading=analogRead(A0);
  if(reading>200;)
  {signal++};
  signal<<1;
}
///////////////////////////////
}

void loop() {
  // put your main code here, to run repeatedly:

// motors::motors()
 /* something.goHere(50, 50, 50, 1);
  delay(500);
  something.goHere(10, 10, 10, 179);
  delay(500);
  something.goHere(-10, -10, -10, 90);
  delay(500);
  something.goHere(-50, -50, -50, 1);
*/


}
