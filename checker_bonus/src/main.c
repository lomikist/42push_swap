/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:34:25 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:34:27 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_part1(t_engine *engine, char *command)
{
	if (!ft_strcmp(command, "rb\n"))
	{
		rotate(&engine->stack_b);
		return (1);
	}
	else if (!ft_strcmp(command, "sb\n"))
	{
		swap(&engine->stack_b);
		return (1);
	}
	else if (!ft_strcmp(command, "pa\n"))
	{
		pop_push(&engine->stack_b, &engine->stack_a);
		return (1);
	}
	else if (!ft_strcmp(command, "rrr\n"))
	{
		rev_rotate(&engine->stack_b);
		rev_rotate(&engine->stack_a);
		return (1);
	}
	return (0);
}

int	exec_part2(t_engine *engine, char *command)
{
	if (!ft_strcmp(command, "rra\n"))
	{
		rev_rotate(&engine->stack_a);
		return (1);
	}
	if (!ft_strcmp(command, "pb\n"))
	{
		pop_push(&engine->stack_a, &engine->stack_b);
		return (1);
	}
	else if (!ft_strcmp(command, "rr\n"))
	{
		rotate(&engine->stack_b);
		rotate(&engine->stack_a);
		return (1);
	}
	else if (!ft_strcmp(command, "ss\n"))
	{
		swap(&engine->stack_a);
		swap(&engine->stack_b);
		return (1);
	}
	return (0);
}

int	exec(t_engine *engine, int fd)
{
	char	*command;

	command = get_next_line(fd);
	while (command && command[0] != '\0')
	{
		if (exec_part1(engine, command))
			;
		else if (exec_part2(engine, command))
			;
		else if (!ft_strcmp(command, "sa\n"))
			swap(&engine->stack_a);
		else if (!ft_strcmp(command, "rrb\n"))
			rev_rotate(&engine->stack_b);
		else if (!ft_strcmp(command, "ra\n"))
			rotate(&engine->stack_a);
		else
		{
			free(command);
			return (EXIT_FAILURE);
		}
		free(command);
		command = get_next_line(fd);
	}
	free(command);
	return (EXIT_SUCCESS);
}

int	check(t_engine *engine)
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

int	main(int argc, char **argv)
{
	t_engine	engine;
	int			free_args;

	engine.stack_a = (t_stack){.head = NULL, .tail = NULL, .count = 0};
	engine.stack_b = (t_stack){.head = NULL, .tail = NULL, .count = 0};
	free_args = 0;
	if (argc > 1)
	{
		argv = parse_args(&argc, argv, &free_args);
		if (argc != 1 && !init_stack(argc - 1, argv, &engine)
			&& !exec(&engine, 0))
		{
			if (check(&engine))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(2, "Error\n", 6);
		if (free_args)
			free_2d_array((void **)argv, argc - 1);
		free_engine(&engine);
	}
	return (0);
}
