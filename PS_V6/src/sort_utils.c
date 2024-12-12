#include "push_swap.h"

int is_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->top)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void comb_sort(t_stack *a)
{
    int gap;
    int swapped;
    int i;

    swapped = 1;
    gap = a->top + 1;
    i = 0;
    while (gap > 1 || swapped)
    {
        if (gap > 1)
            gap = (gap * 10) / 13;
        swapped = 0;
        while (i + gap <= a->top)
        {
            if (a->data[i] > a->data[i + gap])
            {
                int temp = a->data[i];
                a->data[i] = a->data[i + gap];
                a->data[i + gap] = temp;
                swapped = 1;
            }
            i++;
        }
    }
}

void sort_stack(t_stack *a, t_stack *b)
{
    comb_sort(a);
    while (!is_sorted(a))
    {
        if (a->data[a->top] > a->data[a->top - 1])
            sa(a);
        else
            pb(a, b);
    }
    while (b->top >= 0)
        pa(a, b);
}