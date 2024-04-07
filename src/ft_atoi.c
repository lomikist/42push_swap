#include "../includes/stack.h"
#include <limits.h>

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

int	ft_atoi(char *str)
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
