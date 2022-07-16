#ifndef PARSE_H
#define PARSE_H
#include "stack.h"
// TODO: check for a better way of doing this
typedef struct Keywords {
    char *push, *pop, *add, *print; //
} Keywords;

Keywords get_keywords();

void run_(const char *filename, Stack *stack);

unsigned concatenate(unsigned x, unsigned y);

// A line of code will be given
void parse_content(char content[256], Stack *stack);
#endif