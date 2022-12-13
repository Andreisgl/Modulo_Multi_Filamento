#include "Stepper.h"

// Define pin connections & motor's steps per revolution

Stepper motor1;
void setup()
{
  motor1.init_stepper(2, 3, 200);
}
void loop()
{
  //motor1.step_stepper(0);
  //delay(100);

  motor1.move_stepper(1, 5, 0);
  delay(2000);
} 