#include "../../Inc/pushswap.h"

void switch_data(t_stack *stack)
{
    t_stack_node *third;
    t_stack_node *first;
    t_stack_node *second;

    if (stack->top && stack->top->next)
    {
        first = stack->top;
        second = stack->top->next;
	    third = second->next;
	    second->prev = NULL;
	    first->next = third;
	    third->prev = first;
	    second->next = first;
	    first->prev = second;
	    stack->top = second;
    }
}

void rotate_data(t_stack *stack)
{
    t_stack_node *first;
    t_stack_node *second;
    t_stack_node *last;

    if (stack->top && stack->bottom)
    {
        first = stack->top;
        second = stack->top->next;
        last = stack->bottom;
        last->next = first;
        first->prev = last;
        first->next = NULL;
        second->prev = NULL;
        stack->top = second;
        stack->bottom = first;
    }
}

void reverse_rotate_data(t_stack *stack)
{
    t_stack_node *first;
    t_stack_node *second;
    t_stack_node *last;

    if (stack->top && stack->bottom)
    {
        first = stack->top;
        second = stack->bottom->prev;
        last = stack->bottom;
        first->prev = last;
        last->next = first;
        last->prev = NULL;
        second->next = NULL;
        stack->top = last;
        stack->bottom = second;
    }
}