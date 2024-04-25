/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:13:24 by dpaco             #+#    #+#             */
/*   Updated: 2023/12/14 22:02:32 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next_node;
	}
	return (count);
}

int	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next_node)
	{
		if (stack->nbr > stack->next_node->nbr)
			return (0);
		stack = stack->next_node;
	}
	return (1);
}

t_stack_node	*find_last(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next_node)
		node = node->next_node;
	return (node);
}

t_stack_node	*find_min(t_stack_node *node)
{
	int				min;
	t_stack_node	*min_node;

	if (!node)
		return (NULL);
	min = INT_MAX;
	while (node)
	{
		if (min > node->nbr)
		{
			min = node->nbr;
			min_node = node;
		}
		node = node->next_node;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *node)
{
	int				max;
	t_stack_node	*max_node;

	if (!node)
		return (NULL);
	max = INT_MIN;
	while (node)
	{
		if (node->nbr > max)
		{
			max = node->nbr;
			max_node = node;
		}
		node = node->next_node;
	}
	return (max_node);
}
