#include "../includes/stack.h"

t_node	*create_node(int index, int data)
{
	t_node	*new_node;

	new_node = NULL;
	new_node->index = index;
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

int	push(t_stack *stack, t_node *node)
{
	if (stack->head != NULL)
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
	return (0);
}

int	swap(t_stack *stack)
{
	int	temp_index;
	int	temp_data;

	if (stack != NULL && (stack.head != stack.tail))
	{
		temp_data = stack.head.data;
		temp_index = stacl.head.index;
		stack.head.data = stack.head.prev.data;
		stack.head.index = stack.head.prev.index;
		stack.head.prev.index = temp_index;
		stack.head.prev.data = temp_data;
		return (1);
	}
	return (0);
}