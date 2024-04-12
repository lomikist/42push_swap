#include "../includes/checker_bonus.h"

void	exec(t_engine *engine, int fd)
{
	char	*command;

	command = get_next_line(fd);
	while (command)
	{
		if (command[0] == '\0')
			break ;
		else if (!ft_strcmp(command, "rra\n"))
			rev_rotate(&engine->stack_a);
		else if (!ft_strcmp(command, "rrb\n"))
			rev_rotate(&engine->stack_b);
		else if (!ft_strcmp(command, "ra\n"))
			rotate(&engine->stack_a);
		else if (!ft_strcmp(command, "rb\n"))
			rotate(&engine->stack_b);
		else if (!ft_strcmp(command, "sa\n"))
			swap(&engine->stack_a);
		else if (!ft_strcmp(command, "sb\n"))
			swap(&engine->stack_b);		
		else if (!ft_strcmp(command, "ss\n"))
		{
			swap(&engine->stack_a);
			swap(&engine->stack_b);
		}
		else if (!ft_strcmp(command, "pa\n"))
			pop_push(&engine->stack_b, &engine->stack_a);
		else if (!ft_strcmp(command, "pb\n"))
			pop_push(&engine->stack_a, &engine->stack_b);
		else if (!ft_strcmp(command, "rrr\n"))
		{
			rev_rotate(&engine->stack_b);
			rev_rotate(&engine->stack_a);
		}
		else if (!ft_strcmp(command, "rr\n"))
		{
			rotate(&engine->stack_b);
			rotate(&engine->stack_a);
		}
		else
			message("Error\n", 6, EXIT_FAILURE);
		command = get_next_line(fd);
	}
}

int	check(t_engine *engine)
{
	int		i;
	t_node	*current;

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

	engine.stack_a.head = NULL;
	engine.stack_a.tail = NULL;
	engine.stack_b.head = NULL;
	engine.stack_b.tail = NULL;
	engine.stack_a.count = 0;
	engine.stack_b.count = 0;
	init_stack(argc - 1, argv + 1, &engine);
	exec(&engine, 0);
	if (check(&engine))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}