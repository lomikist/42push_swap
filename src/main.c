#include "../includes/stack.h"

void	find_max_and_rotate(t_stack *stack, char *r, char *rr)
{
	t_node	*temp;
	int		i;

	temp = stack->head;
	i = -1;
	while (++i < stack->count)
	{
		if (temp->supos_index == stack->count - 1)
		{
			if (i > stack->count / 2)
			{
				while (i != stack->count)
				{
					rev_rotate(stack, rr);
					++i;
				}
			}
			else
				while (--i >= 0)
					rotate(stack, r);
			break ;
		}
		temp = temp->prev;
	}
}

void	push_swap_3(t_engine *e)
{
	int	d1;
	int	d2;
	int	d3;

	d1 = e->stack_a.head->supos_index;
	d2 = e->stack_a.head->prev->supos_index;
	d3 = e->stack_a.head->prev->prev->supos_index;
	if (d1 > d2 && d2 > d3)
	{
		rotate(&e->stack_a, "ra");
		swap(&e->stack_a, "sa");
	}
	else if (d1 > d2 && d3 > d1)
		swap(&e->stack_a, "sa");
	else if (d1 > d3 && d3 > d2)
		rotate(&e->stack_a, "ra");
	else if (d1 > d3 && d2 > d1)
		rev_rotate(&e->stack_a, "rra");
	else if (d3 > d1 && d2 > d3)
	{
		rev_rotate(&e->stack_a, "rra");
		swap(&e->stack_a, "sa");
	}
}

void	push_swap_small(t_engine *e)
{
	if (e->stack_a.count == 2)
		rotate(&e->stack_a, "ra");
	else if (e->stack_a.count == 3)
		push_swap_3(e);
	else if (e->stack_a.count == 4)
	{
		find_max_and_rotate(&e->stack_a, "ra", "rra");
		pop_push(&e->stack_a, &e->stack_b, "pb");
		push_swap_3(e);
		pop_push(&e->stack_b, &e->stack_a, "pa");
		rotate(&e->stack_a, "ra");
	}
	else
	{
		find_max_and_rotate(&e->stack_a, "ra", "rra");
		pop_push(&e->stack_a, &e->stack_b, "pb");
		push_swap_small(e);
		pop_push(&e->stack_b, &e->stack_a, "pa");
		rotate(&e->stack_a, "ra");
	}
}

void	push_swap(t_engine *e)
{
	int	chunk;

	if (e->stack_a.count <= 5)
		return (push_swap_small(e));
	chunk = generate_chunk(e->stack_a.count);
	while (e->stack_a.count)
	{
		if (e->stack_a.head->supos_index <= e->stack_b.count)
			pop_push(&e->stack_a, &e->stack_b, "pb");
		else if (e->stack_a.head->supos_index <= e->stack_b.count + chunk)
		{
			pop_push(&e->stack_a, &e->stack_b, "pb");
			rotate(&e->stack_b, "rb");
		}
		else
			rotate(&e->stack_a, "ra");
	}
	while (e->stack_b.count > 0)
	{
		find_max_and_rotate(&e->stack_b, "rb", "rrb");
		pop_push(&e->stack_b, &e->stack_a, "pa");
	}
}

int	main(int argc, char **argv)
{
	t_engine	engine;

	engine.stack_a.head = NULL;
	engine.stack_a.tail = NULL;
	engine.stack_b.head = NULL;
	engine.stack_b.tail = NULL;
	engine.stack_a.count = 0;
	engine.stack_b.count = 0;
	init_components(argc - 1, argv + 1, &engine);
	push_swap(&engine);
	return (0);
}
