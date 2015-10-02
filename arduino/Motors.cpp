#include "Motors.h"

motors::motors()
{
    p_xnew = p_ynew = p_znew = xco = yco = zco = 0;
    step_x  = new Stepper(200, 53, 52, 51, 50);
    step_y  = new Stepper(200, 49, 48, 47, 46);
    step_z1 = new Stepper(200, 45, 44, 43, 42);
    step_z2 = new Stepper(200, 41, 40, 39, 38); 
  
    theServo.attach(7);   
  
    this->step_x->setSpeed(20);
    this->step_y->setSpeed(20);
    this->step_z1->setSpeed(20);
    this->step_z2->setSpeed(20);
}

motors::~motors()
{
    delete step_x;
    delete step_y;
    delete step_z1;
    delete step_z2;
}

void motors::goHere(int xnew,int ynew, int znew, int dir)
{
  theServo.write(dir);  
  
  delay(500);
  
  if(xco<xnew){
      for(int i=0; i<xnew; i++){
       this->step_x->step(1);
     }
      xco = xnew;
  }
  if(xco>xnew){
     for(int i=0; i>xnew; i--){
       this->step_x->step(-1);
     }
      xco = xnew;
  }
  if(yco<ynew){
     for(int i=0; i<ynew; i++){
       this->step_y->step(1);
     }
     yco = ynew;
  }
  if(yco>ynew){
     for(int i=0; i>ynew; i--){
       this->step_y->step(-1);
     }
     yco = ynew;
  }
  if(zco<znew){
     for(int i=0; i<znew; i++){
       this->step_z1->step(1);
       delay(5);
       this->step_z2->step(1);
     }
     zco = znew;
  }
  if(zco>znew){
     for(int i=0; i>znew; i--){
         this->step_z1->step(-1);
         delay(5);
         this->step_z2->step(-1);
     }
     zco = znew;
  }
}




