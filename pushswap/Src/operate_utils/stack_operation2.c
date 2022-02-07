#include "../../Inc/pushswap.h"


t_stack	*create_stack(void)
{
	t_stack *ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	ret->cnt = 0;
	ret->top = NULL;
    ret->bottom = NULL;
	return (ret);
}

void delete_stack(t_stack *stack)
{
	if (stack == NULL)
		return;
    while (stack->cnt > 0)
        delete_front(stack);
    free(stack);
    stack = NULL;
}