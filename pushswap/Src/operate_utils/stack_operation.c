#include "../../Inc/pushswap.h"

void insert_front(t_stack* stack, int data)
{
    t_stack_node *tmp;

    tmp = (t_stack_node *)malloc(sizeof(t_stack_node));
    tmp->data = data;
    tmp->prev = NULL;
    if (++stack->cnt == 1)
    {
        tmp->next = NULL;
        stack->top = tmp;
        stack->bottom = tmp;
        return ;
    }
    tmp->next = stack->top;
    stack->top->prev = tmp;
    if (stack->cnt == 2)
        stack->bottom = stack->top;
    stack->top = tmp;
}

void insert_back(t_stack* stack, int data)
{
    t_stack_node *tmp;

    tmp = (t_stack_node *)malloc(sizeof(t_stack_node));
    tmp->data = data;
    tmp->next = NULL;
    if (++stack->cnt == 1)
    {
        tmp->prev = NULL;
        stack->top = tmp;
        stack->bottom = tmp;
        return ;
    }
    tmp->prev = stack->bottom;
    stack->bottom->next = tmp;
    stack->bottom = tmp;
}

void delete_front(t_stack* stack)
{
    t_stack_node *tmp;

    if (stack->cnt == 0)
        return ;
    tmp = stack->top;
    stack->top = stack->top->next;
    if (stack->cnt == 1)
        stack->bottom = NULL;
    else
        stack->top->prev = NULL;
    free(tmp);
    tmp = NULL;
    stack->cnt--;
}

void delete_back(t_stack* stack)
{
    t_stack_node *tmp;

    if (stack->cnt == 0)
        return ;
    tmp = stack->bottom;
    stack->bottom = stack->bottom->prev;
    if (stack->cnt == 1)
        stack->top = NULL;
    else
        stack->bottom->next = NULL;
    free(tmp);
    tmp = NULL;
    stack->cnt--;
}

void delete_curr_node(t_stack* stack, t_stack_node **curr)
{
    t_stack_node *prev;
    t_stack_node *next;

    prev = (*curr)->prev;
    next = (*curr)->next;

    prev->next = next;
    next->prev = prev;
    free(*curr);
    stack->cnt--;
}

// int main()
// {
//     t_stack *ex;

//     ex =creat_stack();

//     insert_front(ex, 1);
// }