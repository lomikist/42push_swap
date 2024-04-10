#include "../includes/stack_bonus.h"
#include <limits.h>


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

void	message(char *sms, int count, int status)
{
	write(2, sms, count);
	exit(status);
}

long	foo(char *str, int sign)
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
	number = foo(str, sign);
	if (number < INT_MIN || number > INT_MAX)
		message("Error\n", 6, EXIT_FAILURE);
	return (number);
}
