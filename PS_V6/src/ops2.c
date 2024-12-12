/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:08:40 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 13:09:10 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(t_stack *b)
{
    int i;
    int temp;

    i = b->top;
    if (b->top > 0)
    {
        int temp = b->data[b->top];
        while (i > 0)
        {
            b->data[i] = b->data[i - 1]
            i--;
        }
        b->data[0] = temp;
        write(1, "rb\n", 3);
    }
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}

void rra(t_stack *a)
{
    int i;
    int temp;

    i = 0;
    if (a->top > 0)
    {
        temp = a->data[0];
        while (i < a->top)
        {
            a->data[i] = a->data[i + 1]
            i++;
        }
        a->data[a->top] = temp;
        write(1, "rra\n", 4);
    }
}

void rrb(t_stack *b)
{
    int temp;
    int i;

    i = 0;
    if (b->top > 0)
    {
        temp = b->data[0];
        while (i < b->top)
        {
            b->data[i] = b->data[i + 1];
            i++;
        }
        b->data[b->top] = temp;
        write(1, "rrb\n", 4);
    }
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}