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
    String data = serial_check_master_command(incoming);
    if(data == "\\") //If it has not a master command:
    {
      data = incoming;
      //Send to other serial port (printer). TODO
      Serial.println("Command for printer!")
    }
    else // If it does have a master command
    {
      //Keep parsing command.
      String command = acode_parse_command(data, 0); // Parse first command.
      String aux = command;
      Serial.print("Code Command: ");
      Serial.print( command ); //Get command

      Serial.print("\tFirst letter: ");
      Serial.print( command[0] ); //Get command

      switch (command[0])
      {
        case 'A': // A-code "A" is for movement
        Serial.println("\t!");
          break;
      }
      
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

String acode_parse_command(String input, int pos)
{
  String aux1 = input;
  String aux2 = input;
  aux1.remove(aux1.indexOf(" ")); //Separate from first space forward.
  aux2.remove(0, aux2.indexOf(" "));

  String output[] = {aux1, aux2};
  return output[pos];
}