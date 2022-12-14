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
    String data = incoming;
    //incoming = strtok(incoming, ":");

    if(data[0] == m_command[0])
    {
      
      data.remove(data.indexOf((incoming[3]))+1);
      if(data == m_command) // If master command is recognized...
      {
        Serial.println("Master command = true!");
        

        data = incoming; // Parse data that comes after it.
        data.remove(0, data.indexOf((incoming[3])) + 1);
        Serial.println(data);
      }
      else // Or else...
      {
        //Send data to other serial port. TODO!!!!!!!!
      }
        
      
      
      
    }
  }
} 