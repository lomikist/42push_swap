#include "../includes/stack.h"

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

void	push(t_stack *stack, t_node *node)
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
