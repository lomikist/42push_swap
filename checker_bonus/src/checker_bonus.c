#include "../includes/checker_bonus.h"

void	init_stack(int argc, char **argv, t_engine *engine)
{
	t_node	*node;
	int		number;
	int		i;

	i = argc;
	while (argv[--i] && i >= 0)
	{
		number = ft_atoi(argv[i]);
		node = create_node(number, i);
		push(&engine->stack_a, node);
	}
}

int main(int argc, char **argv)
{
	t_engine	engine;

	engine.stack_a.head = NULL;
	engine.stack_a.tail = NULL;
	engine.stack_b.head = NULL;
	engine.stack_b.tail = NULL;
	engine.stack_a.count = 0;
	engine.stack_b.count = 0;
	init_stack(argc - 1, argv + 1, &engine);

	// exec(&engine, 0);
	// check(&engine);
	print_stack(&engine.stack_a);
	return (0);
}