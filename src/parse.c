#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "exec.h"
#include "string.h"
#include <ctype.h>

Keywords get_keywords() {
    Keywords keywords;
    keywords.push = "push";
    keywords.pop = "pop";
    keywords.add = "add";
    keywords.print = "print";

    return keywords;
}

void run_(const char *filename, Stack *stack) {
    FILE *file;
    char buffer[256];
    file = fopen(filename, "r");
	if(file == NULL) {
		printf("Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
    // Put line by line on the buffer
    while(fgets(buffer, 256, file) != NULL) {
        parse_content(buffer, stack);
    }
}
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}
// A line of code will be given
void parse_content(char content[256], Stack *stack) {
    Keywords keywords;
    keywords = get_keywords();
    if(strncmp(keywords.push, content, 4) == 0) {
        int pushed_value = 0;
        for(int i = 0; i < (int)strlen(content)+1; i++) {
            if(isdigit(content[i])) {
                int casted_char = content[i] - '0';
                pushed_value = concatenate(pushed_value, casted_char);
            }
        }
        push(stack, pushed_value);
    } else if (strncmp(keywords.add, content, 3) == 0) {
        if(stack->size == 0) {
            printf("The stack is empty!");
            exit(EXIT_FAILURE);
        }
        add(stack);
    } else if (strncmp(keywords.pop, content, 3) == 0) {
        if(stack->size == 0) {
            printf("The stack is empty!");
            exit(EXIT_FAILURE);
        }
        pop(stack);
    } else if (strncmp(keywords.print, content, 5) == 0) {
        if(stack->size == 0) {
            printf("[]\n");
            exit(EXIT_SUCCESS);
        }
        if(stack->size == 1) {
            printf("[ %i ]\n", stack_peek(stack));
            exit(EXIT_SUCCESS);
        }
        if(stack->size > 1) {
            printf("[ ");
            for(int i = 0; i < stack->size; i++) {
                if(i == stack->size-1) {
                    printf("%i ", stack->array[i]);
                    break;
                }
                printf("%i, ", stack->array[i]);
            }
            printf("]\n");
        }
    }
}
