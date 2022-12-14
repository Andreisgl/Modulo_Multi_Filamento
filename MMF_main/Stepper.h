#ifndef STEPPER_H
#define STEPPER_H
#include <Arduino.h>

class Stepper
{
  public:
    void init_stepper(int dir, int step, int stepsPU);
    void move_stepper(float dist_unit, float vel_UpS, int dir);
    void step_stepper(int dir);
    void set_steps_unit(int spu);
  private:
    int dirPin;
    int stepPin;
    int stepsPU;
};

/*
void init_stepper(int dir, int step, int stepsPU);

void move_stepper(int dist_unit, int vel_UpS);

void step_stepper(int dir);
*/
#endif