#include "stack.h"
#include "exec.h"
#include <stdio.h>
void push(Stack *stack, int item) {
    stack_add(stack, item);
}
void pop(Stack *stack) {
    stack_pop(&stack);
}
void add(Stack *stack) {
    int top1, top2;
    top1 = stack_peek(stack);
    stack_pop(stack);
    top2 = stack_peek(stack);
    stack_pop(stack);
    stack_add(stack, top1+top2);
}
void print(Stack *stack) {
    printf("[ %i ]", stack_peek(&stack));
}