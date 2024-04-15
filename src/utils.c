#include "../includes/stack.h"
#include <limits.h>

void	bubble_sort(int *arr, int count)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < count)
	{
		j = i;
		while (++j < count)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int	is_sorted(t_engine *engine)
{
	int		i;
	t_node	*current;

	if (engine->stack_b.count != 0)
		return (0);
	i = 0;
	current = engine->stack_a.head;
	while (++i < engine->stack_a.count)
	{
		if (current->data > current->prev->data)
			return (0);
		current = current->prev;
	}
	return (1);
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

long	to_long(char *str)
{
	long	number;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number = 0;
	while (*str != '\0')
	{
		if (*str <= '9' && *str >= '0')
		{
			number = number * 10 + (*str - '0');
			str++;
		}
		else
			return (0);
	}
	return (number * sign);
}

void	free_2d_array(void **arr, int n_rows)
{
	int	i;

	i = -1;
	while (++i < n_rows)
		free(arr[i]);
	free(arr);
}
