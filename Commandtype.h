#ifndef _COMMAND_TYPE_
#define _COMMAND_TYPE_

enum Pcommand {
  C_ARITHMETIC,
  C_PUSH,
  C_POP,
  C_LABEL,
  C_GOTO,
  C_IF,
  C_FUNCTION,
  C_RETURN,
  C_CALL
};

#endif