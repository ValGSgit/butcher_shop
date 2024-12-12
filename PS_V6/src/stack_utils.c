/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:02:06 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 13:02:24 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *a, t_stack *b)
{
    int i;

    i = a->top;
    printf("Stack A: ");
    while (i >= 0)
        printf("%d ", a->data[i--]);
    printf("\n");

    i = b->top;
    printf("Stack B: ");
    while (i >= 0)
        printf("%d ", b->data[i--]);
    printf("\n");
}

void quit(t_stack *a, t_stack *b, int code)
{
    free_stack(a);
    free_stack(b);
    exit(code);
}