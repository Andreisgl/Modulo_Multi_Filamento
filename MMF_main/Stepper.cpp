#include "Arduino.h"
#include "Stepper.h"

int dirPin;
int stepPin;
int stepsPerUnit; // Steps per unit

void Stepper::init_stepper(int dir, int step, int stepsPU)
{
  dirPin = dir;
  stepPin = step;
  stepsPerUnit = stepsPU;

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void Stepper::move_stepper(float dist_unit, float vel_UpS, int dir)
{
  //dist = 2, vel = 1;

  //time = vel/dist
  int total_steps = dist_unit * stepsPerUnit; //400
  int steps_psec = vel_UpS * stepsPerUnit; // 200
  int time  = total_steps/steps_psec; // 2
  //int steps_psec = total_steps/time;
  double sec_pstep = float(time)/total_steps; // 0,005
  int intsec_pstep = (sec_pstep * 1000.0);

  for(int i=total_steps; i>0; i--)
  {
    step_stepper(dir);
    delay(intsec_pstep);
    //delay(5);
  }
}

void Stepper::step_stepper(int dir)
{
  if(dir == 0) //Clockwise
  {
    digitalWrite(dirPin, HIGH);
  }
  else
  {
    digitalWrite(dirPin, LOW);
  }
  digitalWrite(stepPin, HIGH);
  digitalWrite(stepPin, LOW);
}

void Stepper::set_steps_unit(int spu)
{
  stepsPerUnit = spu;
}