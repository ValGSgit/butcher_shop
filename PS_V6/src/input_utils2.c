/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:01:19 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 15:45:41 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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

void init_stack(t_stack *stack, int size, char **av)
{
	//printf("fks up here");
    stack->data = (int *)ft_calloc(sizeof(int), size);
	stack->index = ft_calloc(sizeof(int), size);
	stack->endindex = ft_calloc(sizeof(int), size);
    if (!stack->data || !stack->data || !stack->endindex)
    {
        perror("Error allocating memory for stack");
		free_stack(stack);
        exit(EXIT_FAILURE);
    }
	init_index(stack, size, av);
    stack->top = -1;
	free_input(av);
}

void free_stack(t_stack *stack)
{
    if (stack->data)
        free(stack->data);
	else if (stack->index)
		free(stack->index);
	else if (stack->endindex)
		free(stack->endindex);
	free(stack);
}
