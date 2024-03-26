#include "../includes/stack.h"

void	error_message(char *sms, int count)
{
	write(1, sms, count);
	exit(EXIT_FAILURE);
}

void	stack_init(int argc, char **argv, t_engine *engine)
{
	int		i;
	// int		j;
	t_node	*node;

	i = 0;
	// j = -1;
	if (argc <= 1)
		error_message("Wrong count of arguments!", 25);
	else
	{
		while (argv[++i])
		{
			if (argv[i][0] == '0' && !argv[i][1])
			{
				node = create_node(i, 0);
				push(&engine->stack_a, node);
			}
			else if (ft_atoi(argv[i]))
			{
				node = create_node(i, ft_atoi(argv[i]));
				push(&engine->stack_a, node);
			}
			else
				printf("%s\n", "error");
		}
	}
}

void print_stack(t_stack *stack) {
	int i = 0;

	if (stack == NULL) {
        printf("Error: Stack is Empty\n");
        return;
    }

    printf("Stack contents:\n");
    t_node *current = stack->tail;
    while (i < stack->count) {
        printf("Index: %d, Data: %d\n", current->index, current->data);
        current = current->next;
		i++;
    }
}

int	main(int argc, char **argv)
{
	t_engine engine;
	engine.stack_a.head = NULL;
	engine.stack_a.tail = NULL;
	engine.stack_b.head = NULL;
	engine.stack_b.tail = NULL;
	engine.stack_a.count = 0;
	engine.stack_b.count = 0;
	stack_init(argc, argv, &engine);

	print_stack(&engine.stack_a);
	return (0);
}