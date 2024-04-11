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

int	swap(t_stack *stack, char *cmd)
{
	int	temp_data;

	if (stack != NULL && (stack->head != stack->tail))
	{
		temp_data = stack->head->data;
		stack->head->data = stack->head->prev->data;
		stack->head->prev->data = temp_data;
		write(1, cmd, 2);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	rotate(t_stack *stack, char *cmd)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->head = stack->head->prev;
		stack->tail = stack->head->next;
		write(1, cmd, 2);
		write(1, "\n", 1);
	}
	return (0);
}

int	revRotate(t_stack *stack, char *cmd)
{
	if (stack != NULL && stack->count != 0 && (stack->head != stack->tail))
	{
		stack->tail = stack->tail->next;
		stack->head = stack->tail->prev;
		write(1, cmd, 3);
		write(1, "\n", 1);
	}
	return (0);
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
