/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:34:49 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:34:53 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"
#include <limits.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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
	if (*str == '0')
		return (0);
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

void	free_engine(t_engine *s)
{
	int		i;
	t_node	*tmp;

	i = -1;
	while (++i < s->stack_a.count)
	{
		tmp = s->stack_a.head;
		s->stack_a.head = s->stack_a.head->prev;
		free(tmp);
	}
	i = -1;
	while (++i < s->stack_b.count)
	{
		tmp = s->stack_b.head;
		s->stack_b.head = s->stack_b.head->prev;
		free(tmp);
	}
}

char	**parse_args(int *argc, char **argv, int *heap_flag)
{
	char	**args;

	*heap_flag = 0;
	if (*argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*argc = 1;
		while (args[*argc - 1] != NULL)
			++(*argc);
		*heap_flag = 1;
	}
	else
		args = argv + 1;
	return (args);
}
