#include "stack.h"
#include <limits.h>

int	init_sorted_array(int *arr, int len, char **args)
{
	int		i;
	long	num;

	i = -1;
	while (args[++i])
	{
		num = to_long(args[i]);
		if (args[i][0] == '0' && !args[i][1])
			arr[i] = 0;
		else if (num > INT_MAX || num < INT_MIN || num == 0)
			return (EXIT_FAILURE);
		arr[i] = num;
	}
	bubble_sort(&arr[0], len);
	return (EXIT_SUCCESS);
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

int	check_for_duplicate(int *arr, int size)
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
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_stack(int *arr, int len, char **args, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;
	int		index;

	i = len - 1;
	while (i >= 0 && args[i])
	{
		number = to_long(args[i]);
		index = find_index(&arr[0], number, len);
		node = create_node(number, index);
		if (!node)
			return (EXIT_FAILURE);
		push(&engine->stack_a, node);
		--i;
	}
	return (EXIT_SUCCESS);
}

int	init_components(int len, char **args, t_engine *engine)
{
	int		*arr;
	int		status;

	status = EXIT_SUCCESS;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		status = EXIT_FAILURE;
	if (!status)
		status = !status && init_sorted_array(&arr[0], len, args);
	if (!status)
		status = !status && check_for_duplicate(&arr[0], len);
	if (!status)
		status = !status && init_stack(&arr[0], len, args, engine);
	free(arr);
	return (status);
}
