#ifndef ACODE_PARSER_H
#define ACODE_PARSER_H
#include <Arduino.h>

class AParser
{
  public:
    void parser_setup();
    String serial_check_master_command(String incoming);
    String acode_parse_command(String input, int pos);

    bool A1(String parameters);
  private:
  
};
#endif