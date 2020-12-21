#include "monty.h"

/**
 * getPchar - prints the character at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

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

/**
 * getPstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

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

/**
 * getPint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getPint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		dprintf(STDERR_FILENO, ERR_PINT, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * getPop - removes the top element of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getPop(stack_t **stack, unsigned int line_number)
{
	stack_t **tmp;

	if (!stack)
	{
		dprintf(STDERR_FILENO, ERR_POP, line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * getSwap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getSwap(stack_t **stack, unsigned int line_number)
{
	stack_t **tmp;
	int len;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_SWAP, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	stack->n = stack->next->n;
	stack->next->n = tmp->n;
}
