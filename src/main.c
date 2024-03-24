#include "../includes/stack.h"

void	error_message(char *sms, int count)
{
	write(1, sms, count);
	exit(EXIT_FAILURE);
}

void	stack_init(int argc, char **argv, t_engine *engine)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	j = -1;
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

int	main(int argc, char **argv)
{
	t_engine engine;

	stack_init(argc, argv, &engine);
}