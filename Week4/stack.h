#ifndef _STACK_H
#define _STACK_H

typedef int stack_t;
typedef struct _stack* stack;

stack stack_create();
void stack_destroy(stack s);
void stack_push(stack s, stack_t value);
void stack_pop(stack s);
stack_t stack_top(stack s);

int stack_is_empty(stack s);
int stack_size(stack s);
void stack_clear(stack s);

#endif
