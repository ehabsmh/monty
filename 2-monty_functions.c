#include "monty.h"

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;

	
	if (top)
	{
		nth_2 = top->next;

		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		
		if (nth_2)
		{
			nth_2->n /= top->n;
			free(*stack);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *nth_2 = NULL;

	
	if (top)
	{
		nth_2 = top->next;

		if (nth_2)
		{
			nth_2->n *= top->n;
			free(*stack);
			(*stack) = nth_2;
			(*stack)->prev = NULL;
			return;
		}
	}

	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

}
