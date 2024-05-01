/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:33:18 by arsargsy          #+#    #+#             */
/*   Updated: 2024/04/17 22:33:21 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*create_node(int data, int supos_index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->data = data;
		new_node->supos_index = supos_index;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	return (new_node);
}

void	push(t_stack *stack, t_node *node)
{
	if (stack->count != 0)
	{
		stack->head->next = node;
		node->next = stack->tail;
		node->prev = stack->head;
		stack->tail->prev = node;
		stack->head = node;
	}
	else
	{
		stack->tail = node;
		stack->head = node;
		stack->tail->next = node;
		stack->head->next = node;
		stack->tail->prev = node;
		stack->head->prev = node;
	}
	stack->count++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->prev;
		stack->tail->prev = stack->head;
		stack->head->next = stack->tail;
		temp->next = NULL;
		temp->prev = NULL;
		stack->count--;
	}
	return (temp);
}

void	free_engine(t_engine *s)
{
	int		i;
	t_node	*tmp;

	i = -1;
	while (++i < s->stack_a.count)
	{
		tmp = s->stack_a.head;
		s->stack_a.head = s->stack_a.head->prev;
		free(tmp);
	}
	i = -1;
	while (++i < s->stack_b.count)
	{
		tmp = s->stack_b.head;
		s->stack_b.head = s->stack_b.head->prev;
		free(tmp);
	}
}

void	find_max_and_rotate(t_stack *stack, char *r, char *rr)
{
	t_node	*temp;
	int		i;

	temp = stack->head;
	i = -1;
	while (++i < stack->count)
	{
		if (temp->supos_index == stack->count - 1)
		{
			if (i > stack->count / 2)
			{
				while (i != stack->count)
				{
					rev_rotate(stack, rr);
					++i;
				}
			}
			else
				while (--i >= 0)
					rotate(stack, r);
			break ;
		}
		temp = temp->prev;
	}
}
