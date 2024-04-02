#include "../includes/stack.h"

t_node	*create_node(int data, int supos_index)
{
	t_node	*new_node;

	new_node = malloc((sizeof(int) * 2) + (sizeof(void *) * 2));
	// new_node->index = index;
	new_node->data = data;
	new_node->supos_index = supos_index;
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
	}
	stack->count--;
	return (temp);
}

int	swap(t_stack *stack)
{
	// int	temp_index;
	int	temp_data;

	if (stack != NULL && (stack->head != stack->tail))
	{
		temp_data = stack->head->data;
		// temp_index = stack->head->index;
		stack->head->data = stack->head->prev->data;
		// stack->head->index = stack->head->prev->index;
		stack->head->prev->data = temp_data;
		// stack->head->prev->index = temp_index;
		return (1);
	}
	return (0);
}

int	rotate(t_stack *stack, char *cmd)
{
	if (stack != NULL && (stack->head != stack->tail))
	{
		stack->head = stack->head->prev;
		stack->tail = stack->head->next;
		write(1, cmd, 2);
		write(1, "\n", 1);
	}
	return (0);
}

int	revRotate(t_stack *stack)
{
	if (stack != NULL && (stack->head != stack->tail))
	{
		stack->tail = stack->tail->next;
		stack->head = stack->tail->prev;
	}
	return (0);
}

