/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:01:53 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/16 18:15:46 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the stack structure
typedef struct s_node {
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack {
    t_node  *top;
}   t_stack;

// Stack operation prototypes
void ft_free(char **ar);
int     check(char **av);
int	    inrange(char **av);
int	ft_strlen(const char *s);
long int	ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**splitavs(int ac, char **av);
int	argcount(char **av);
void    sa(t_stack *a);
void    ra(t_stack *a);
void    rra(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
int     stack_size(t_stack *stack);
void    rotate_to_top(t_stack *stack, int index, int is_stack_a);
void    comb_sort(t_stack *a, t_stack *b);


#endif