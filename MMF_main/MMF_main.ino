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
    Serial.print("Return: ");
    String data = serial_check_master_command(incoming);
    if(data == "\\") //If it has not a master command:
    {
      //Send to other serial port (printer).
    }
    else // If it does have a master command
    {
      //Keep parsing command.
    }
  }

}

String serial_check_master_command(String incoming)
{
  String data = incoming;
    data.remove(data.indexOf((incoming[3]))+1);
    if(data == m_command) // If master command is recognized...
    {
      data = incoming; // Parse data that comes after it.
      data.remove(0, data.indexOf((incoming[3])) + 1);
      return data;
    }
    else // Or else...
    {
      //Send data to other serial port. TODO!!!!!!!!
      return "\\";
    }
    
}