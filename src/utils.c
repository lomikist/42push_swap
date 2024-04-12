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

long	to_long(char *str, int sign)
{
	long	number;

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

long	ft_atoi(char *str)
{
	long	number;
	int		sign;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number = to_long(str, sign);
	if (number < INT_MIN || number > INT_MAX)
		message("Error\n", 6, EXIT_FAILURE);
	return (number);
}
