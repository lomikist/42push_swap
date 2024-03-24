int	foo(char *str, int i, unsigned int number, int sign)
{
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			number = number * 10 + (str[i] - '0');
			i++;
		}
		else
			return (0);
	}
	return (number * sign);
}

int	ft_atoi(char *str)
{
	int				i;
	unsigned int	number;
	int				sign;

	sign = 1;
	i = 0;
	number = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (foo((char *)str, i, number, sign));
}
