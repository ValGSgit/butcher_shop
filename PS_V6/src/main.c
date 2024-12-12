/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:01:45 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/12 15:46:38 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    printf("fks up here");
    av = splitavs(ac, av);
    ac = argcount(av);
    if (check(av) == 0)
        return (free_input(av), quit(stack_a, stack_b, 1), 1);
    init_stack(stack_a, ac, av);
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}