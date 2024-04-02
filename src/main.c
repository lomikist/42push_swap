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

void	stack_init(int argc, char **argv, t_engine *engine)
{
	int		i;
	int		index;
	t_node	*node;
	int		*arr;

	i = 0;
	if (argc <= 1)
		error_message("Wrong count of arguments!", 25);
	else
	{
		arr = malloc(sizeof(int) * (argc - 1));
		init_sorted_array(&arr[0], argc, argv);
		while (argv[++i])
		{
			if (argv[i][0] == '0' && !argv[i][1])
			{
				index = find_index(&arr[0], 0, argc - 1);
				node = create_node(i, 0, index);
			}
			else if (ft_atoi(argv[i]))
			{
				index = find_index(&arr[0], ft_atoi(argv[i]), argc - 1);
				node = create_node(i, ft_atoi(argv[i]), index);
			}
			else
				exit(EXIT_FAILURE);
			push(&engine->stack_a, node);
		}
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

int	main(int argc, char **argv)
{
	t_engine	engine;

	engine.stack_a.head = NULL;
	engine.stack_a.tail = NULL;
	engine.stack_b.head = NULL;
	engine.stack_b.tail = NULL;
	engine.stack_a.count = 0;
	engine.stack_b.count = 0;
	stack_init(argc, argv, &engine);
	
	
	rotate(&engine.stack_a);
	revRotate(&engine.stack_a);
	pop(&engine.stack_a);
	print_stack(&engine.stack_a);
	return (0);
}
