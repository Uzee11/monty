#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * ... (unchanged)
 */

/**
 * process_file - Process Monty byte code instructions from a file
 * ... (unchanged)
 */

/**
 * process_line - Process a single line of Monty byte code instruction
 * @line: Monty byte code instruction
 * @line_number: Line number in the file
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
    char *opcode, *argument;
    int value;

    opcode = strtok(line, " \t\n");
    if (!opcode || opcode[0] == '#') /* Ignore comments and empty lines */
        return;

    if (strcmp(opcode, "push") == 0)
    {
        argument = strtok(NULL, " \t\n");
        if (!argument || !is_integer(argument))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        value = atoi(argument);
        push(stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(*stack);
    }
    /* Add more opcodes as needed */
}

/**
 * is_integer - Check if a string represents an integer
 * ... (unchanged)
 */

/**
 * push - Push a value onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to push
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Print all values on the stack
 * @stack: Pointer to the top of the stack
 */
void pall(const stack_t *stack)
{
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}
