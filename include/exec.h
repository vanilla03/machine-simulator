#ifndef EXEC_KEYWORDS
#define EXEC_KEYWORDS
#include "stack.h"
// Push a number on to the stack
void push(Stack *stack, int item);
// Pop off the first number on the stack
void pop(Stack *stack);
// Pop off the top 2 items on the stack and push their sum on to the stack
void add(Stack *stack);
// Print the value at the top of the stack
void print(Stack *stack);
#endif