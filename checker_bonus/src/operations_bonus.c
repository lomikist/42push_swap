#include "stack_bonus.h"

int	swap(t_stack *stack)
{
	int	temp_data;

	if (stack != NULL && (stack->head != stack->tail))
	{
		temp_data = stack->head->data;
		stack->head->data = stack->head->prev->data;
		stack->head->prev->data = temp_data;
		return (1);
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->head = stack->head->prev;
		stack->tail = stack->head->next;
	}
	return (0);
}

int	rev_rotate(t_stack *stack)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->tail = stack->tail->next;
		stack->head = stack->tail->prev;
	}
	return (0);
}

void	pop_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = pop(from);
	if (tmp)
		push(to, tmp);
}
