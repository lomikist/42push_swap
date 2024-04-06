#include "../includes/stack.h"

void	error_message(char *sms, int count)
{
	write(1, sms, count);
	exit(EXIT_FAILURE);
}

void	init_sorted_array(int *arr, int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '0' && !argv[i][1])
			arr[i - 1] = 0;
		else if (ft_atoi(argv[i]))
			arr[i - 1] = ft_atoi(argv[i]);
	}
	bubbleSort(&arr[0], argc - 1);
}

int	find_index(int *arr, int to_find, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == to_find)
			return i;
		i++;
	}
	return 0;
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

void	init_stack(int *arr, int argc, char **argv, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;
	int		index;

	i = 0;
	while (argv[++i])
	{
		number = ft_atoi(argv[i]);
		if (argv[i][0] == '0' && !argv[i][1])
		{
			index = find_index(&arr[0], 0, argc - 1);
			node = create_node(0, index);
		}
		else if (ft_atoi(argv[i]))
		{
			index = find_index(&arr[0], ft_atoi(argv[i]), argc - 1);
			node = create_node(ft_atoi(argv[i]), index);
		}
		else
			exit(EXIT_FAILURE);
		push(&engine->stack_a, node);
	}
}

void	init_components(int argc, char **argv, t_engine *engine)
{
	int		*arr;

	if (argc <= 1)
		error_message("Wrong count of arguments!", 25);
	else
	{
		arr = malloc(sizeof(int) * (argc - 1));//TODO free
		init_sorted_array(&arr[0], argc, argv);
		if (check_for_dublicate(&arr[0], argc - 1) == 1)
			error_message("duplicated elementttsssssss!", 25);
		init_stack(&arr[0], argc, argv, engine);
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

void	find_max_and_rotate(t_stack *stack)
{
	t_node	*temp;
	int		i;

	temp = stack->head;
	i = 0;
	while (i < stack->count)
	{
		if (temp->supos_index == stack->count - 1)
		{
			if (i >= stack->count / 2)
			{
				while (i != stack->count)
				{
					revRotate(stack, "rrb");
					++i;
				}
			}
			else 
			{
				while (--i >= 0)
				{
					rotate(stack, "rb");
				}
			}
			break ;
		}
		temp = temp->prev;
		i++;
	}
}

void	push_swap(t_engine *e)
{
	int	chunk;

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
		find_max_and_rotate(&e->stack_b);
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
	init_components(argc, argv, &engine);
	// print_stack(&engine.stack_a);
	push_swap(&engine);
	// print_stack(&engine.stack_a);
	return (0);
}
