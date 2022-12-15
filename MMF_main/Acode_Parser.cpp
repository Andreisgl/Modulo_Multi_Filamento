#include "Arduino.h"
#include "Acode_Parser.h"
#include "Stepper.h"

char m_command[] = "MMF:";

Stepper motorA;

void AParser::parser_setup()
{
  motorA.init_stepper(2, 3, 1);
}
String AParser::serial_check_master_command(String incoming)
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

String AParser::acode_parse_command(String input, int pos)
{
  String aux1 = input;
  String aux2 = input;
  aux1.remove(aux1.indexOf(" ")); //Separate from first space forward.
  aux2.remove(0, aux2.indexOf(" "));

  String output[] = {aux1, aux2};
  return output[pos];
}

bool AParser::A1(String parameters) //Home axis
{
    //motorA.init_stepper(2, 3, 200);
    motorA.init_stepper(2, 3, 10);
    motorA.move_stepper(1,1,1);
    return true;  
}