#ifndef STACK
#define STACK

typedef struct Stack
{
	int *array;
	int size;
	int capacity;
} Stack;

// Create a new stack with given capacity
Stack new_stack(int capacity);
// Resize stack if needed
void stack_resize(Stack *stack);
// Add new item
void stack_add(Stack *stack, int item);
// Remove first item from stack
void stack_pop(Stack *stack);
// Clean the stack
void stack_clean(Stack *stack);
#endif