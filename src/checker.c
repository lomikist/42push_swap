#include "../includes/checker.h"

void    exec(t_engine *e, int fd)
{
    (void)e;
    (void)fd;
}

void    check(t_engine *e)
{
    (void)e;
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