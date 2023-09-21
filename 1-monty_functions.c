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
	stack_t *top = *stack, *nth_2 = NULL;
	int temp = 0;

	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			temp = top->n;
			top->n = nth_2->n;
			nth_2->n = temp;
			return;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
