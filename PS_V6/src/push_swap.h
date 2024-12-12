#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
    int *data;
    int *index;
    int top;
    int *endindex;
} t_stack;

void    init_index(t_stack *a, int size, char **av);
void    init_endindex(t_stack *a, int size);
void    print_stack(t_stack *a, t_stack *b);
void    init_stack(t_stack *stack, int size, char **av);
void    free_stack(t_stack *stack);
void    quit(t_stack *a, t_stack *b, int code);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
int     check(char **av);
void	*ft_calloc(size_t nmemb, size_t size);
void        ft_putstr(const char *s);
long int	ft_atoi(const char *str);
char	    **splitavs(int ac, char **av);
char	    **ft_split(char const *s, char c);
char        *ft_strdup(const char *src);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
int         ft_strlen(const char *s);
void	    free_input(char **argv);
char	    *argtostr(int ac, char **av);
int         argcount(char **av);
int     is_sorted(t_stack *a);
void    sort_stack(t_stack *a, t_stack *b);

#endif