#include "monty.h"

/**
 * getPchar - prints the character at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 *

void getPchar(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		dprintf(STDERR_FILENO, ERR_PCHAR, line_number);
		exit(EXIT_FAILURE);
	}
	if (stack->n < 0 || stack->n > 127)
	{
		dprintf(STDERR_FILENO, ERR_NOCHAR, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", itoa(stack->n));
}

**
 * getPstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 *

void getPstr(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		printf("\n");
	}
	while (stack)
	{
		if (stack->n < 1 || stack->n > 127)
		{
			return;
		}
		printf("%c", itoa(stack->n));
		stack = stack->next;
	}
}

**
 * getPop - removes the top element of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getPop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *cur = *stack;

	if (!cur)
	{
		dprintf(STDERR_FILENO, ERR_POP, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (cur->next != NULL)
	{
		tmp = cur->next;
	}
	free(cur);
	*stack = tmp;
}

/**
 * getSwap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getSwap(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp = *stack;
	stack_t *cur;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_SWAP, line_number);
		exit(EXIT_FAILURE);
	}
	cur = tmp->next;
	n = tmp->n;
	tmp->n = cur->n;
	cur->n = n;
}
