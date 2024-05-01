/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:40:24 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:40:25 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include "../libft/libft.h"

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

t_node	*create_node(int data, int supos_index);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack, char *cmd);
void	rotate(t_stack *stack, char *cmd);
void	rev_rotate(t_stack *stack, char *cmd);
void	pop_push(t_stack *from, t_stack *to, char *cmd_name);
int		init_components(int len, char **args, t_engine *engine);
void	bubble_sort(int *arr, int count);
int		generate_chunk(int size);
int		is_sorted(t_engine *engine);
void	free_engine(t_engine *s);
long	to_long(char *str);
void	find_max_and_rotate(t_stack *stack, char *r, char *rr);
void	free_2d_array(void **arr, int n_rows);

#endif
