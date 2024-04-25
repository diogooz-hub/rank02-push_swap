/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:20:47 by dpaco             #+#    #+#             */
/*   Updated: 2023/12/10 11:57:01 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next_node)
		rra(a);
	if ((*a)->nbr > (*a)->next_node->nbr)
		sa(a);
}
