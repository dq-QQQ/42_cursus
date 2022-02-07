#include "../../Inc/pushswap.h"

void switch_data(t_stack *stack)
{
    t_stack_node *tmp;

    if (stack->top && stack->top->next)
    {
        tmp = stack->top->next->next;
        stack->top->next->next = stack->top;
        stack->top->next->prev = NULL;
        stack->top->prev = stack->top->next->prev;
        stack->top->next = tmp;
    }
}