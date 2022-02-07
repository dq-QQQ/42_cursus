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
        tmp->next = NULL;
        stack->top = tmp;
        stack->bottom = tmp;
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
    tmp = stack->top;
    stack->bottom = stack->bottom->prev;
    
    if (stack->cnt == 1)
        stack->top = NULL;
    else
        stack->bottom->next = NULL;
    free(tmp);
    tmp = NULL;
    stack->cnt--;
}

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
    while (stack->cnt > 0)
        delete_front(stack);
    free(stack);
    stack = NULL;
}

int main(){
  t_stack *dq;

  dq = create_stack();
  


  insert_front(dq, 5);

   insert_front(dq, 6);

//   insert_front(dq, 7);


//    insert_back(dq, 10);

//       insert_back(dq, 11);

//    insert_back(dq, 12);

//    delete_front(dq);
//    delete_back(dq);

//    delete_stack(dq);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");

}