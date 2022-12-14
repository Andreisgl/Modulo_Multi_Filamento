#include "Stepper.h"

// Define pin connections & motor's steps per revolution

Stepper motor1;
void setup()
{
  Serial.begin(9600);

  motor1.init_stepper(2, 3, 200);
}

char m_command[] = "MMF:";
void loop()
{
  //motor1.move_stepper(2, 1, 0);
  //delay(2000);

  if(Serial.available())
  {
    String incoming = Serial.readString();
    
    //incoming = strtok(incoming, ":");

    char sample;
    for(int i=0; i< sizeof(m_command); i++)
    {
      sample += incoming[i];
    }
    Serial.println(sample);
    if(sample == m_command)
    {
      
    }
  }
} 