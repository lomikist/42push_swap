#include "../includes/checker_bonus.h"

void	init_stack(int len, char **args, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;

	if (len == 1)
	{
		args = ft_split(args[0], ' ');
		len = -1;
		while (args[++len] != NULL);
	}
	i = len;
	while (args[--i] && i >= 0)
	{
		number = ft_atoi(args[i]);
		node = create_node(number, i);
		push(&engine->stack_a, node);
	}
}

void	pop_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = pop(from);
	if (tmp)
		push(to, tmp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	exec(t_engine *engine, int fd)
{
	char	*command;

	command = get_next_line(fd);
	while (command)
	{
		if (command[0] == '\0')
			break ;
		else if (!ft_strcmp(command, "rra\n"))
			revRotate(&engine->stack_a);
		else if (!ft_strcmp(command, "rrb\n"))
			revRotate(&engine->stack_b);
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
			revRotate(&engine->stack_b);
			revRotate(&engine->stack_a);
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