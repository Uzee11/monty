#include "monty.h"

/* Global variable - pointer to the top of the stack */
stack_t *stack = NULL;

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
void process_line(char *line, unsigned int line_number)
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
        push(&stack, value);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    /* Add more opcodes as needed */
}

/**
 * is_integer - Check if a string represents an integer
 * ... (unchanged)
 */

/**
 * push - Push a value onto the stack
 * ... (unchanged)
 */

/**
 * pall - Print all values on the stack
 * ... (unchanged)
 */

/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void pint(const stack_t *stack, unsigned int line_number)
{
    if (!stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}
