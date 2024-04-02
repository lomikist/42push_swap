#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				supos_index;
	int				data;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_stack;

typedef struct s_engine
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_engine;

int		ft_atoi(char *str);
t_node	*create_node(int index, int data, int supos_index);
int	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
int	swap(t_stack *stack);
int rotate(t_stack *stack);
int	revRotate(t_stack *stack);
void 	bubbleSort(int *arr, int count);
void	print_stack(t_stack *stack);


#endif
