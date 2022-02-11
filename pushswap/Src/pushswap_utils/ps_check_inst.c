#include "../../Inc/pushswap.h"

int	is_same_inst(t_stack_node *curr)
{
	if ((curr->data == 1 && curr->next->data == 1)
        || (curr->data == 2 && curr->next->data == 2)
        || (curr->data == 5 && curr->next->data == 7)
        || (curr->data == 7 && curr->next->data == 5)
        || (curr->data == 6 && curr->next->data == 8)
        || (curr->data == 8 && curr->next->data == 6)
        || (curr->data == 3 && curr->next->data == 4)
        || (curr->data == 4 && curr->next->data == 3))
		    return (1);
	return (0);
}



int	combine_inst(t_stack_node *curr)
{
	if ((curr->data == 1 && curr->next->data == 2)
        || (curr->data == 2 && curr->next->data == 1))
		return (9);
	if ((curr->data == 5 && curr->next->data == 6)
        || (curr->data == 6 && curr->next->data == 5))
		return (10);
	if ((curr->data == 7 && curr->next->data == 8)
        || (curr->data == 8 && curr->next->data == 7))
		return (11);
	return (0);
}

void check_inst(t_stack* stack)
{
    t_stack_node *curr;
    int flag;

    curr = stack->top;
    while (curr->next)
    {
        if (is_same_inst(curr))
        {
            curr->data = 0;
            curr->next->data = 0;
            curr = curr->next->next;
            continue;
        }
        flag = combine_inst(curr);
        if (flag)
        {
            curr->data = 0;
            curr->next->data = flag;
            curr = curr->next->next;
            continue;
        }
        curr = curr->next;
    }
}
