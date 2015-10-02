#ifndef Motors_h
#define Motors_h

// the #include statment and code go here...
#include "Arduino.h"
#include <Stepper.h>
#include <Servo.h>

//instantiate class:

class motors
{
public:
    motors();
    ~motors();
    void goHere(int xnew,int ynew, int znew, int dir);
    
private:
    Stepper* step_x;
    Stepper* step_y;
    Stepper* step_z1;
    Stepper* step_z2;   
    Servo theServo;
    int p_xnew;
    int p_ynew;
    int p_znew;
    int xco;
    int yco;
    int zco;
};

#endif 

