#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of list
 * @lineN: line number
 * Return: void
 */

void add(stack_t **stack, unsigned int lineN)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n += tmp->n;
}

/**
 * sub - substracts the top two elements of the stack
 * @stack: head of list
 * @lineN: line number
 * Return: void
 */

void sub(stack_t **stack, unsigned int lineN)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n -= tmp->n;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: head of list
 * @lineN: line number
 * Return: void
 */

void mul(stack_t **stack, unsigned int lineN)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n *= tmp->n;
}

/**
 * div - divide the second by the top element of the stack
 * @stack: head of list
 * @lineN: line number
 * Return: void
 */

void div(stack_t **stack, unsigned int lineN)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	if (stack->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n /= tmp->n;
}

/**
 * mod - modulo the second by the top element of the stack
 * @stack: head of list
 * @lineN: line number
 * Return: void
 */

void mod(stack_t **stack, unsigned int lineN)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", lineN);
		exit(EXIT_FAILURE);
	}
	if (stack->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", lineN);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n %= tmp->n;
}
