/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:32:55 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:32:58 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_swap_3(t_engine *e)
{
	int	d1;
	int	d2;
	int	d3;

	d1 = e->stack_a.head->supos_index;
	d2 = e->stack_a.head->prev->supos_index;
	d3 = e->stack_a.head->prev->prev->supos_index;
	if (d1 > d2 && d2 > d3)
	{
		rotate(&e->stack_a, "ra");
		swap(&e->stack_a, "sa");
	}
	else if (d1 > d2 && d3 > d1)
		swap(&e->stack_a, "sa");
	else if (d1 > d3 && d3 > d2)
		rotate(&e->stack_a, "ra");
	else if (d1 > d3 && d2 > d1)
		rev_rotate(&e->stack_a, "rra");
	else if (d3 > d1 && d2 > d3)
	{
		rev_rotate(&e->stack_a, "rra");
		swap(&e->stack_a, "sa");
	}
}

void	push_swap_small(t_engine *e)
{
	if (e->stack_a.count == 2)
		rotate(&e->stack_a, "ra");
	else if (e->stack_a.count == 3)
		push_swap_3(e);
	else if (e->stack_a.count == 4)
	{
		find_max_and_rotate(&e->stack_a, "ra", "rra");
		pop_push(&e->stack_a, &e->stack_b, "pb");
		push_swap_3(e);
		pop_push(&e->stack_b, &e->stack_a, "pa");
		rotate(&e->stack_a, "ra");
	}
	else
	{
		find_max_and_rotate(&e->stack_a, "ra", "rra");
		pop_push(&e->stack_a, &e->stack_b, "pb");
		push_swap_small(e);
		pop_push(&e->stack_b, &e->stack_a, "pa");
		rotate(&e->stack_a, "ra");
	}
}

void	push_swap(t_engine *e)
{
	int	chunk;

	if (e->stack_a.count <= 5)
		return (push_swap_small(e));
	chunk = generate_chunk(e->stack_a.count);
	while (e->stack_a.count)
	{
		if (e->stack_a.head->supos_index <= e->stack_b.count)
			pop_push(&e->stack_a, &e->stack_b, "pb");
		else if (e->stack_a.head->supos_index <= e->stack_b.count + chunk)
		{
			pop_push(&e->stack_a, &e->stack_b, "pb");
			rotate(&e->stack_b, "rb");
		}
		else
			rotate(&e->stack_a, "ra");
	}
	while (e->stack_b.count > 0)
	{
		find_max_and_rotate(&e->stack_b, "rb", "rrb");
		pop_push(&e->stack_b, &e->stack_a, "pa");
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
		if (*argc == 1)
			write(2, "Error\n", 6);
		*heap_flag = 1;
	}
	else
		args = argv + 1;
	return (args);
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
		if (!init_components(argc - 1, argv, &engine))
		{
			if (!is_sorted(&engine))
				push_swap(&engine);
		}
		else
			write(2, "Error\n", 6);
		if (free_args)
			free_2d_array((void **)argv, argc - 1);
		free_engine(&engine);
	}
	return (0);
}
