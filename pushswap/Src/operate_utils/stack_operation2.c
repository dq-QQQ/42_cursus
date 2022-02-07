#include "../../Inc/pushswap.h"


t_stack	*create_stack(void)
{
	t_stack *ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	ret->cnt = 0;
	ret->top = (t_stack_node *)malloc(sizeof(t_stack_node));
	ret->top->data = 0;
	ret->top->prev = NULL;
	ret->top->next = NULL;
    ret->bottom = ret->top;
	return (ret);
}

void delete_stack(t_stack *stack)
{
    while (stack->cnt > 0)
        delete_front(stack);
    free(stack);
    stack = NULL;
}