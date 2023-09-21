#include "monty.h"

/**
 * swap - Swaps the top two elements
 * @stack: The stack
 * @line_number: Line numbers of .m files
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
