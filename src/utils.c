#include "../includes/stack.h"

void	print_stack(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 0;

	printf("Stack contents:\n");
	current = stack->head;
	while (i < stack->count)
	{
		printf("Data: %d, suppos: %d\n", current->data, current->supos_index);
		current = current->prev;
		i++;
	}
}