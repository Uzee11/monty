#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Function to handle push opcode */
void push(stack_t **stack, int value)
{
    /* Implement push logic here */
}

/* Function to handle pall opcode */
void pall(stack_t **stack)
{
    /* Implement pall logic here */
}

int main(int argc, char *argv[])
{
    /* ... your main logic here */

    /* Example usage within your code */
    stack_t *stack = NULL; // Initialize your stack
    push(&stack, 10); /* Example: Pushing value 10 */
    pall(&stack); /* Example: Printing all values in the stack */

    return EXIT_SUCCESS;
}

