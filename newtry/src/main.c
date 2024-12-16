#include "push_swap.h"

// Function prototypes
void sa(t_stack *a);
void sb(t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
int stack_size(t_stack *stack);
void print_stack(t_stack *stack, char stack_name);

// Swap the top two elements of stack a
void sa(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *first = a->top;
        t_node *second = a->top->next;

        first->next = second->next;
        second->next = first;
        a->top = second;
        write(1, "sa\n", 3);
    }
}

// Push the top element from a to b
void pb(t_stack *a, t_stack *b) {
    if (a->top) {
        t_node *temp = a->top;
        a->top = a->top->next;
        temp->next = b->top;
        b->top = temp;
        write(1, "pb\n", 3);
    }
}

// Push the top element from b to a
void pa(t_stack *a, t_stack *b) {
    if (b->top) {
        t_node *temp = b->top;
        b->top = b->top->next;
        temp->next = a->top;
        a->top = temp;
        write(1, "pa\n", 3);
    }
}

// Rotate stack a upwards
void ra(t_stack *a) {
    if (a->top && a->top->next) {
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

// Rotate stack b upwards
void rb(t_stack *b) {
    if (b->top && b->top->next) {
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

// Reverse rotate stack a downwards
void rra(t_stack *a) {
    if (a->top && a->top->next) {
        t_node *prev = NULL;
        t_node *current = a->top;

        while (current->next) {
            prev = current;
            current = current->next;
        }
        current->next = a->top;
        a->top = current;
        prev->next = NULL;
        write(1, "rra\n", 4);
    }
}

// Reverse rotate stack b downwards
void rrb(t_stack *b) {
    if (b->top && b->top->next) {
        t_node *prev = NULL;
        t_node *current = b->top;

        while (current->next) {
            prev = current;
            current = current->next;
        }
        current->next = b->top;
        b->top = current;
        prev->next = NULL;
        write(1, "rrb\n", 4);
    }
}

// Function to get stack size
int stack_size(t_stack *stack) {
    int count = 0;
    t_node *current = stack->top;
    while (current) {
        current = current->next;
        count++;
    }
    return count;
}

// Function to print the stack (for debugging)
void print_stack(t_stack *stack, char stack_name) {
    t_node *current = stack->top;
    printf("Stack %c: ", stack_name);
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Insertion Sort Algorithm
void insertion_sort(t_stack *a, t_stack *b)
{
    while (a->top) {
        // Push the top of a to b
        pb(a, b);
        print_stack(b, 'B'); // Debug: Print stack b after push

        // Ensure stack b remains sorted in descending order
        if (b->top->next && b->top->value < b->top->next->value) {
            sa(b); // Swap if out of order
            print_stack(b, 'B'); // Debug: Print stack b after swap
        }
    }

    // Push all elements back from b to a to complete the sort
    while (b->top) {
        pa(a, b);
        print_stack(a, 'A'); // Debug: Print stack a after push back
    }
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
    
    argv = splitavs(argc, argv); // Ensure splitavs skips the program name
    argc = argcount(argv);
    if (!check(argv) || !inrange(argv))
        return (ft_free(argv), exit(1), 1);
    
    // Initialize stack a with input numbers (from last to first for correct order)
    i = argc - 1;
    while (i >= 0)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node) {
            ft_free(argv);
            return 1;
        }
        new_node->value = atoi(argv[i]);
        new_node->next = a.top;
        a.top = new_node;
        free(argv[i]);
        i--;
    }
    free(argv);
    
    // Perform insertion sort
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
    t_node *curr = b.top;
    write(1, "Sorted Stack b:\n", 16);
    while (curr) {
        char num_str[12];
        int len = sprintf(num_str, "%d\n", curr->value);
        write(1, num_str, len);
        current = curr->next;
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