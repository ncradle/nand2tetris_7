#include <fstream>
#include <string>
#include <vector>
#include "Commandtype.h"

class Parser {
 private:
  std::vector<std::string> command_list;
  std::vector<std::string>::iterator pointa_command;
  std::string command;

 public:
  Parser(std::ifstream *fp);
  bool hasMoreCommands();
  void advance();
  Pcommand commandType();
  std::string arg1();
  int arg2();
};
