/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:34:24 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/16 18:34:30 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the top two elements of stack a
void sa(t_stack *a)
{
    if (a->top && a->top->next)
    {
        t_node *first = a->top;
        t_node *second = a->top->next;

        first->next = second->next;
        second->next = first;
        a->top = second;
        write(1, "sa\n", 3);
    }
}

// Rotate stack a upwards
void ra(t_stack *a)
{
    if (a->top && a->top->next)
    {
        t_node *first = a->top;
        t_node *last = a->top;

        while (last->next)
            last = last->next;

        a->top = first->next;
        first->next = NULL;
        last->next = first;
        write(1, "ra\n", 3);
    }
}

// Rotate stack a downwards
void rra(t_stack *a)
{
    if (a->top && a->top->next)
    {
        t_node *prev = NULL;
        t_node *current = a->top;

        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        current->next = a->top;
        a->top = current;
        prev->next = NULL;
        write(1, "rra\n", 4);
    }
}

// Push the top element from a to b
void pb(t_stack *a, t_stack *b)
{
    if (a->top)
    {
        t_node *temp = a->top;
        a->top = a->top->next;
        temp->next = b->top;
        b->top = temp;
        write(1, "pb\n", 3);
    }
}

// Push the top element from b to a
void pa(t_stack *a, t_stack *b)
{
    if (b->top)
    {
        t_node *temp = b->top;
        b->top = b->top->next;
        temp->next = a->top;
        a->top = temp;
        write(1, "pa\n", 3);
    }
}

// Get the size of the stack
int stack_size(t_stack *stack)
{
    int count = 0;
    t_node *current = stack->top;
    while (current)
    {
        current = current->next;
        count++;
    }
    return count;
}

// Rotate the element at index to the top



// Rotate stack b upwards
 void rb(t_stack *b)
 {
    if (b->top && b->top->next) 
    {
        t_node *first = b->top;
        t_node *last = b->top;

        while (last->next)
            last = last->next;

        b->top = first->next;
        first->next = NULL;
        last->next = first;
        write(1, "rb\n", 3);
    }
}

// Rotate stack b downwards
void rrb(t_stack *b)
{
    if (b->top && b->top->next)
    {
        t_node *prev = NULL;
        t_node *current = b->top;

        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        current->next = b->top;
        b->top = current;
        prev->next = NULL;
        write(1, "rrb\n", 4);
    }
}

void rotate_to_top(t_stack *stack, int index, int is_stack_a)
{
    int size = stack_size(stack);
    if (index < size / 2)
    {
        for (int i = 0; i < index; i++)
        {
            if (is_stack_a) ra(stack);
            else rb(stack);
        }
    } 
    else
    {
        for (int i = 0; i < size - index; i++)
        {
            if (is_stack_a) rra(stack);
            else rrb(stack);
        }
    }
}


void comb_sort(t_stack *a, t_stack *b)
{
    int size = stack_size(a);
    int gap = size;
    const float shrink_factor = 1.3;
    int sorted = 0;

    while (!sorted) {
        // Update the gap value
        gap = (int)(gap / shrink_factor);
        if (gap < 1)
            gap = 1;
        // Assume sorted
        sorted = 1;

        int i = 0;
        t_node *current = a->top;
        while (i + gap < size) {
            // Get nodes to compare
            int value1 = current->value;
            t_node *gap_node = current;
            for (int j = 0; j < gap; j++)
                gap_node = gap_node->next;
            int value2 = gap_node->value;

            // Compare and swap if necessary
            if (value1 > value2) {
                // Rotate to bring the two elements to the top of stack a
                rotate_to_top(a, i, 1);
                pb(a, b); // Move the first element to b
                rotate_to_top(a, gap - 1, 1);
                pb(a, b); // Move the second element to b
                sa(b);    // Swap them in b
                pa(a, b); // Move back to a
                pa(a, b); // Move back to a

                // Rebuild the stack to original order
                rotate_to_top(a, size - i - 2, 1);
                sorted = 0;
            }
            current = current->next;
            i++;
        }
    }
}

int is_sorted(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp->top && tmp->top->next)
    {
        if (tmp->top > tmp->top->next)
            return (0);
        tmp->top = tmp->top->next;
    }
    return (1);
}
void insertion_sort(t_stack *a, t_stack *b)
{
    while (a->top)
    {
        // Push top of a to b
        pb(a, b);
        // Ensure b is sorted in descending order
        while (b->top && b->top->next && b->top->value > b->top->next->value)
        {
            sa(b); // Swap top two elements of b
        }
    }
    // Push all elements back from b to a
    while (b->top)
    {
        pa(a, b);
    }
    if (!is_sorted(a))
        insertion_sort(a, b);
}

int main(int argc, char **argv)
{
    t_stack a = {NULL};
    t_stack b = {NULL};
    int i;

    // Check for valid input
    if (argc < 2) {
        write(1, "Error: No numbers provided\n", 27);
        return 1;
    }
    argv = splitavs(argc, argv);
    argc = argcount(argv);
    if (!check(argv) || !inrange(argv))
        return (ft_free(argv), exit(1), 1);
    // Initialize stack a with input numbers
    i = 0;
    while (i < argc)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
            return 1;
        new_node->value = atoi(argv[i]);
        new_node->next = a.top;
        a.top = new_node;
        free(argv[i]);
        i++;
    }
    free(argv);
    // Perform comb sort
    insertion_sort(&a, &b);
    //comb_sort(&a, &b);

    // (Optional) Print the sorted stack
    t_node *current = a.top;
    write(1, "Sorted Stack a:\n", 16);
    while (current) {
        char num_str[12];
        int len = sprintf(num_str, "%d\n", current->value);
        write(1, num_str, len);
        current = current->next;
    }

    // Free allocated memory
    while (a.top)
    
    {
        t_node *temp = a.top;
        a.top = a.top->next;
        free(temp);
    }
    return (0);
}
