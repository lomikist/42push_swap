#include "../includes/checker.h"

void    exec(t_engine *e, int fd)
{
    (void)e;
    (void)fd;
}

void	init_components(int len, char **args, t_engine *engine)
{
	int		*arr;

	if (len == 1)
	{
		args = ft_split(args[0], ' ');
		len = -1;
		while (args[++len] != NULL);
	}
	if (len <= 0)
		message("Error\n", 6, EXIT_FAILURE);
	else
	{
		arr = malloc(sizeof(int) * len);
		init_sorted_array(&arr[0], len, args);
		if (check_for_dublicate(&arr[0], len) == 1)
			message("Error\n", 6, EXIT_FAILURE);
		init_stack(&arr[0], len, args, engine);
		free(arr);
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
	init_components(argc - 1, argv + 1, &engine);
	//print_stack(&engine.stack_a);
	exec(&engine, 0);
    check(&engine);
	//print_stack(&engine.stack_a);
	return (0);
}