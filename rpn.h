#include "../StackADT/stack.h"

typedef struct result Result;

struct result {
  int error;
  int status;
};


Result evaluate(char *expression);