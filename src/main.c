#include "../includes/stack.h"

void	message(char *sms, int count, int status)
{
	write(2, sms, count);
	exit(status);
}

void	init_sorted_array(int *arr, int len, char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '0' && !args[i][1])
			arr[i] = 0;
		else if (ft_atoi(args[i]))
			arr[i] = ft_atoi(args[i]);
		else
			message("Error\n", 6, EXIT_FAILURE);
	}
	bubbleSort(&arr[0], len);
}

int	find_index(int *arr, int to_find, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == to_find)
			return (i);
		i++;
	}
	return (0);
}

int	check_for_dublicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack(int *arr, int len, char **args, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;
	int		index;
	int		is_sorted;

	is_sorted = 1;
	i = len;
	while (args[--i] && i >= 0)
	{
		number = ft_atoi(args[i]);
		if (is_sorted && i != len - 1 && number > node->data)
			is_sorted = 0;
		index = find_index(&arr[0], number, len);
		node = create_node(number, index);
		push(&engine->stack_a, node);
	}
	if (is_sorted)
		message("", 0, EXIT_SUCCESS);
}

void	init_components(int len, char **args, t_engine *engine)
{
	int		*arr;

	if (len == 1)
	{
		args = ft_split(args[0], ' ');
		len = -1;
		while (args[++len] != NULL);
	}
	if (len <= 0)
		message("Error\n", 6, EXIT_FAILURE);
	else
	{
		arr = malloc(sizeof(int) * len);
		init_sorted_array(&arr[0], len, args);
		if (check_for_dublicate(&arr[0], len) == 1)
			message("Error\n", 6, EXIT_FAILURE);
		init_stack(&arr[0], len, args, engine);
		free(arr);
	}
}

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
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
					revRotate(stack, rr);
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
		revRotate(&e->stack_a, "rra");
	else if (d3 > d1 && d2 > d3)
	{
		revRotate(&e->stack_a, "rra");
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
	//print_stack(&engine.stack_a);
	push_swap(&engine);
	//print_stack(&engine.stack_a);
	return (0);
}
