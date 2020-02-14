#include "Parser.h"
#include <fstream>
#include <string>

Parser::Parser(std::ifstream *fp) {
  while (!fp->eof()) {
    std::string buff;
    std::string rmtext = "";
    std::getline(*fp, buff);
    for (std::string::iterator str = buff.begin(); str != buff.end(); str++) {
      if (*str == ' ') continue;
      if (*str == '/') break;
      rmtext += *str;
    }
    if (rmtext == "") continue;
    command_list.push_back(rmtext);
  }
  pointa_command = command_list.begin();
}

bool Parser::hasMoreCommands() { return pointa_command != command_list.end(); }

void Parser::advance() {
  command = *pointa_command;
  pointa_command++;
}

Pcommand Parser::commandType() {
  if (command == "push") return C_PUSH;
  if (command == "pop") return C_POP;
  if (command == "label") return C_LABEL;
  if (command == "goto") return C_GOTO;
  if (command == "if-goto") return C_IF;
  if (command == "funcition") return C_FUNCTION;
  if (command == "call") return C_CALL;
  if (command == "return") return C_RETURN;
  return C_ARITHMETIC;
}

std::string Parser::arg1() {
  if (commandType() == C_ARITHMETIC) return command;
  advance();
  return command;
}
int Parser::arg2() { return atoi(command.c_str); }