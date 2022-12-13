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
  //time = vel/dist
  float time_mS = (dist_unit / vel_UpS) * 1000;
  
    int amnt_steps = stepsPerUnit*dist_unit;
    int time_perStep = time_mS/amnt_steps;
    for(int i=amnt_steps; i>0; i--)
    {
      step_stepper(dir);
      delayMicroseconds(int(time_perStep)*1000);
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
