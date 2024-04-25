/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:25:01 by dpaco             #+#    #+#             */
/*   Updated: 2023/12/19 14:12:59 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *number)
{
	if (!(*number == '-' || *number == '+' 
			|| (*number >= '0' && *number <= '9')))
		return (1);
	number++;
	while (*number)
	{
		if (!(*number >= '0' && *number <= '9'))
			return (1);
		number++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next_node;
	}
	return (0);
}

void	clean_av(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free (av);
	return ;
}

void	clean_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		temp = (*stack)->next_node;
		free(*stack);
		*stack = temp;
	}
}

void	exit_errors(t_stack_node **a, char **av_made)
{
	if (av_made)
		clean_av(av_made);
	clean_stack(a);
	ft_printf("Error\n");
	exit (1);
}
