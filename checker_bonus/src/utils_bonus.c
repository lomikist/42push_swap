#include "../includes/stack_bonus.h"
#include <limits.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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
