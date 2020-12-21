#include "monty.h"

/**
 * pchar - prints the character at the top of the stack
 * @stack: stack
 * @lineN: line number
 * Return: void
 */

void pchar(stack_t **stack, unsigned int lineN)
{
	if (!stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", lineN);
		exit(EXIT_FAILURE);
	}
	if (stack->n < 0 || stack->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", lineN);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", itoa(stack->n));
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @lineN: line number
 * Return: void
 */

void pstr(stack_t **stack, unsigned int lineN)
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
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @lineN: line number
 * Return: void
 */

void pint(stack_t **stack, unsigned int lineN)
{
	if (!stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", lineN);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack
 * @lineN: line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int lineN)
{
	stack_t **tmp;

	if (!stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @lineN: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int lineN)
{
	stack_t **tmp;
	int len;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	stack->n = stack->next->n;
	stack->next->n = tmp->n;
}
