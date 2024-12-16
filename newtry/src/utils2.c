/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:25:33 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/16 18:11:12 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_skipspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	neg;
	long int	res;

	i = ft_skipspace(str);
	res = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
    {
		res *= 10;
		res += (int)(str[i] - 48);
		i++;
	}
	return (neg * res);
}


void	free_stack(int **stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack[i] != NULL)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
	stack = NULL;
}


void	quit(int **stack_a, int **stack_b, int yayornay)
{
	if (stack_a || *stack_a)
		free_stack(stack_a);
	if (stack_b || *stack_b)
		free_stack(stack_b);
	if (yayornay == 0)
		exit(0);
	if (yayornay == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}	
}