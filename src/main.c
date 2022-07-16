#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "parse.h"

int main(int argc, char const *argv[]) {

	if(argc <= 1) {
		printf("Usage: executable <file>\n");
		exit(EXIT_FAILURE);
	}
	Stack stack;
	stack = new_stack(4);
	run_(argv[1], &stack);
	stack_clean(&stack);
	return 0;
}
