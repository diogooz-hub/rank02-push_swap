/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:12:47 by dpaco             #+#    #+#             */
/*   Updated: 2023/12/14 22:05:29 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	int		count;
	long	res;

	count = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		count = count * -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return (res * count);
}

void	create_node(t_stack_node **a, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next_node = NULL;
	node->nbr = n;
	if (!(*a))
	{
		*a = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next_node = node;
		node->prev_node = last_node;
	}
}

void	stack_init(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			exit_errors(a, 0);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_errors(a, 0);
		if (error_duplicate(*a, (int)n))
			exit_errors(a, 0);
		create_node(a, (int)n);
		i++;
	}
}

void	stack_init_avmade(t_stack_node **a, char **av_made)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (av_made[i])
	{
		if (error_syntax(av_made[i]))
			exit_errors(a, av_made);
		n = ft_atol(av_made[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_errors(a, av_made);
		if (error_duplicate(*a, (int)n))
			exit_errors(a, av_made);
		create_node(a, (int)n);
		i++;
	}
}
