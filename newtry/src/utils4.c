/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:19 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/16 18:11:31 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	*argtostr(int ac, char **av)
{
	char	*str;
	char	*space;
	char	*tmp;
	int		i;

	str = NULL;
	i = 1;
	space = " ";
	while (i < ac)
	{
		if (str == NULL)
			str = ft_strdup(av[i]);
		else
		{
			tmp = ft_strjoin(str, space);
			free(str);
			str = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
		i++;
	}
	return (str);
}

int	argcount(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**splitavs(int ac, char **av)
{
	char	*str;

	str = argtostr(ac, av);
	av = ft_split(str, 32);
	free(str);
	return (av);
}
