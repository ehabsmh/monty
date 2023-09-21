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
	stack_t *top = *stack, *next;
	int temp;

	if (top)
	{
		next = top->next;
		if (next)
		{
			temp = top->n;
			top->n = next->n;
			next->n = temp;
			return;
		}
	}
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
