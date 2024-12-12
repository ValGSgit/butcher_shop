/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:16:28 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 15:42:56 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t	i;
	size_t	typ;

	typ = nmemb * size;
	if (size && ((typ / size) != nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (free(ptr), NULL);
	i = 0;
	while (i < typ)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void    init_index(t_stack *a, int size, char **av)
{
    int i;
    
    if (!a)
    {
        free_stack(a);
        free_input(av);
        exit(1);
    }
    i = 0;
    while (i < size && a->data != NULL)
    {
        *a->data = (int)ft_atoi(av[i]);
        a->index[i] = i;
        i++;
    }
    init_endindex(a, size);
}

void    init_endindex(t_stack *a, int size)
{
    int *indx;
    int maxt;
    int i;

    if (!a)
    {
        free_stack(a);
        exit(1);
    }
    maxt = 2147483647;
    indx = a->index;
    a->endindex = indx;
    i = 0;
    while (size - 1 > 0)
    {
        if (*a->data < maxt)
        {
            a->endindex[i] = i;
            maxt = *a->data;
        }
        i++;
    }
}

