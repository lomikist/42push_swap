#include "../includes/stack.h"

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
	bubble_sort(&arr[0], len);
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
		while (args[++len] != NULL)
			continue ;
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
