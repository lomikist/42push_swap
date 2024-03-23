/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyepremy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:33:47 by vyepremy          #+#    #+#             */
/*   Updated: 2024/03/21 23:01:10 by vyepremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct Node {
	struct Node	*next;
	int			data;
} node_t;

typedef stuct Stack {
	node_t	*head = NULL;
} stack_t;

#endif
