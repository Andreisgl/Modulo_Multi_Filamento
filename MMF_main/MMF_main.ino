#include "Stepper.h"
#include "Acode_Parser.h"

AParser AParser;


Stepper motor1;

void setup()
{
  Serial.begin(9600);
  AParser.parser_setup();
  // Define pin connections & motor's steps per revolution
  motor1.init_stepper(2, 3, 200);
}


void loop()
{
  //motor1.move_stepper(2, 1, 0);
  //delay(2000);

  if(Serial.available())
  {
    String incoming = Serial.readString();
    String data = AParser.serial_check_master_command(incoming);

    if(data == "\\") //If it has not a master command:
    {
      data = incoming;
      //Send to other serial port (printer). TODO
      Serial.println("Command for printer!");
    }
    else // If it does have a master command
    {
      //Keep parsing command.
      String command = AParser.acode_parse_command(data, 0); // Parse command.
      int command_number;
      String parameters = AParser.acode_parse_command(data, 1); // Parse parameters.
      String aux = command;

      Serial.print("Command: ");
      Serial.print( command ); //Get command

      Serial.print("\tFirst letter: ");
      Serial.print( command[0] );

      Serial.print("\tCommand number: ");
      aux.remove(0,aux.indexOf(aux[0]) + 1);
      command_number = aux.toInt();
      Serial.print(command_number);



      Serial.print("\tParameters: ");
      Serial.print( parameters ); //Get command

      //Serial.println();

      switch (command[0])
      {
        case 'A': // A-code "A" is for movement
        Serial.println("\t!");
          if( AParser.A1(parameters) == true);
          {
            Serial.println("wololo");
          }
          break;
      }
    }



  }

}

