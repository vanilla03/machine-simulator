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
	stack->array[stack->size] = item;
	stack->size++;
}

int stack_peek(Stack *stack) {
	int top = stack->size == 0 ? stack->size : stack->size-1;
	return stack->array[top];
}
// pop off the first number on the stack
void stack_pop(Stack *stack) {
    // Change last value to 0
    stack->array[stack->size-1] = 0;
    stack->size--;
}
int stack_size(Stack *stack) {
	return stack->size;
}
void stack_clean(Stack *stack) {
	free(stack->array);
	stack->size = 0;
	stack->capacity = 0;
}