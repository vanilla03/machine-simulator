#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack new_stack(int capacity) {
    if(capacity < 1) {
        printf("Capacity must be at least 2!");
        exit(EXIT_FAILURE);
    }
	Stack stack;
	// Create an array of integers with a custom capacity
	stack.array = malloc(capacity * sizeof(int));
	stack.size = 0;
	stack.capacity = capacity;

	return stack;
}
void stack_resize(Stack *stack) {
	int *new_array;
	stack->capacity = (stack->capacity * 2); 
	new_array = malloc(stack->capacity * sizeof(int));
	for(int i = 0; i < stack->size; i++) {
		new_array[i] = stack->array[i];
	}
	free(stack->array);
	stack->array = new_array;
}

void stack_add(Stack *stack, int item) {
	if(stack->size == stack->capacity) {
		stack_resize(stack);
	}
    // Move all items to the left
    for(int i = stack->capacity-1; i >= 0; i--) {
        // Break when it reaches to the first index to avoid bugs
        if(i == 0)
            break;
        stack->array[i] = stack->array[i-1];
    }

	stack->array[0] = item;
	stack->size++;
}
// pop off the first number on the stack
void stack_pop(Stack *stack) {
    // Move all values up
	for(int i = 0; i < stack->size; i++) {
        stack->array[i] = stack->array[i+1]; 
	}
    // Change last value to 0
    stack->array[stack->size-1] = 0;
    stack->size--;
}
void stack_clean(Stack *stack) {
	free(stack->array);
	stack->size = 0;
	stack->capacity = 0;
}