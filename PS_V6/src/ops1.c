#include "push_swap.h"

void sa(t_stack *a)
{
    if (a->top > 0)
    {
        int temp = a->data[a->top];
        a->data[a->top] = a->data[a->top - 1];
        a->data[a->top - 1] = temp;
        write(1, "sa\n", 3);
    }
}

void sb(t_stack *b)
{
    if (b->top > 0)
    {
        int temp = b->data[b->top];
        b->data[b->top] = b->data[b->top - 1];
        b->data[b->top - 1] = temp;
        write(1, "sb\n", 3);
    }
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->top >= 0)
    {
        a->data[++a->top] = b->data[b->top--];
        write(1, "pa\n", 3);
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a->top >= 0)
    {
        b->data[++b->top] = a->data[a->top--];
        write(1, "pb\n", 3);
    }
}


