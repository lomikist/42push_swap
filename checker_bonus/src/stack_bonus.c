#include "stack_bonus.h"
#include <limits.h>

t_node	*create_node(int data, int supos_index)
{
	t_node	*new_node;

	new_node = malloc((sizeof(int) * 2) + (sizeof(void *) * 2));
	if (new_node)
	{
		new_node->data = data;
		new_node->supos_index = supos_index;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	return (new_node);
}

int	push(t_stack *stack, t_node *node)
{
	if (stack->count != 0)
	{
		stack->head->next = node;
		node->next = stack->tail;
		node->prev = stack->head;
		stack->tail->prev = node;
		stack->head = node;
	}
	else
	{
		stack->tail = node;
		stack->head = node;
		stack->tail->next = node;
		stack->head->next = node;
		stack->tail->prev = node;
		stack->head->prev = node;
	}
	stack->count++;
	return (0);
}

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->prev;
		stack->tail->prev = stack->head;
		stack->head->next = stack->tail;
		temp->next = NULL;
		temp->prev = NULL;
		stack->count--;
	}
	return (temp);
}

int	check_for_duplicate(t_stack *s)
{
	t_node	*tmp_i;
	t_node	*tmp_j;

	tmp_i = s->head;
	while (tmp_i != s->tail)
	{
		tmp_j = tmp_i->prev;
		while (tmp_j != s->head)
		{
			if (tmp_i->data == tmp_j->data)
				return (EXIT_FAILURE);
			tmp_j = tmp_j->prev;
		}
		tmp_i = tmp_i->prev;
	}
	return (EXIT_SUCCESS);
}

int	init_stack(int len, char **args, t_engine *engine)
{
	t_node	*node;
	long	number;
	int		i;

	i = len - 1;
	while (i >= 0 && args[i])
	{
		number = to_long(args[i]);
		if (args[i][0] == '0' && !args[i][1])
			number = 0;
		else if (number > INT_MAX || number < INT_MIN || number == 0)
			return (EXIT_FAILURE);
		node = create_node(number, i);
		push(&engine->stack_a, node);
		--i;
	}
	return (check_for_duplicate(&engine->stack_a));
}
