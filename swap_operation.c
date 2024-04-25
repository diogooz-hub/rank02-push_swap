/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:38:45 by dpaco             #+#    #+#             */
/*   Updated: 2023/12/14 22:01:33 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	if (!*stack || !((*stack)->next_node))
		return ;
	*stack = (*stack)->next_node;
	(*stack)->prev_node->prev_node = *stack;
	(*stack)->prev_node->next_node = (*stack)->next_node;
	if ((*stack)->next_node)
		(*stack)->next_node->prev_node = (*stack)->prev_node;
	(*stack)->next_node = (*stack)->prev_node;
	(*stack)->prev_node = NULL;
}

void	sa(t_stack_node	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
