/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:09:29 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 13:09:41 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a)
{
    int i;
    int temp;

    i = a->top;
    if (a->top > 0)
    {
        int temp = a->data[a->top];
        while (i > 0)
        {
            a->data[i] = a->data[i - 1]
            i--;
        }
        a->data[0] = temp;
        write(1, "ra\n", 3);
    }
}