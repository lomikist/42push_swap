#include "stack.h"

void	swap(t_stack *stack, char *cmd)
{
	int	temp_data;

	if (stack != NULL && (stack->head != stack->tail))
	{
		temp_data = stack->head->data;
		stack->head->data = stack->head->prev->data;
		stack->head->prev->data = temp_data;
		write(1, cmd, 2);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char *cmd)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->head = stack->head->prev;
		stack->tail = stack->head->next;
		write(1, cmd, 2);
		write(1, "\n", 1);
	}
}

void	rev_rotate(t_stack *stack, char *cmd)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->tail = stack->tail->next;
		stack->head = stack->tail->prev;
		write(1, cmd, 3);
		write(1, "\n", 1);
	}
}

void	pop_push(t_stack *from, t_stack *to, char *cmd_name)
{
	t_node	*tmp;

	tmp = pop(from);
	if (tmp)
	{
		push(to, tmp);
		write(1, cmd_name, 2);
		write(1, "\n", 1);
	}
}
