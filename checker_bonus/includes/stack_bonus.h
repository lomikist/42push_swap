/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:41:09 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:45:23 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
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

long	to_long(char *str);
t_node	*create_node(int data, int supos_index);
int		push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
int		swap(t_stack *stack);
int		rotate(t_stack *stack);
int		rev_rotate(t_stack *stack);
void	pop_push(t_stack *from, t_stack *to);
int		ft_strcmp(char *s1, char *s2);
int		init_stack(int len, char **args, t_engine *engine);
void	free_2d_array(void **arr, int n_rows);
void	free_engine(t_engine *s);
char	**parse_args(int *argc, char **argv, int *heap_flag);

#endif
