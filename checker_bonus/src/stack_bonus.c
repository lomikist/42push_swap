#include "../includes/stack_bonus.h"

void	message(char *sms, int count, int status)
{
	write(2, sms, count);
	exit(status);
}

t_node	*create_node(int data, int supos_index)
{
	t_node	*new_node;

	new_node = malloc((sizeof(int) * 2) + (sizeof(void *) * 2));
	new_node->data = data;
	new_node->supos_index = supos_index;
	new_node->prev = NULL;
	new_node->next = NULL;
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

void	init_stack(int len, char **args, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;

	if (len == 1)
	{
		args = ft_split(args[0], ' ');
		len = -1;
		while (args[++len] != NULL)
			continue ;
	}
	i = len;
	while (args[--i] && i >= 0)
	{
		number = ft_atoi(args[i]);
		node = create_node(number, i);
		push(&engine->stack_a, node);
	}
}
