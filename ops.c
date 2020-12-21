#include "monty.h"

/**
 * getAdd - adds the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getAdd(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_ADD, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, lineN);
	stack->n += tmp->n;
}

/**
 * getSub - substracts the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getSub(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_SUB, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, line_number);
	stack->n -= tmp->n;
}

/**
 * getMul - multiplies the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getMul(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_MUL, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, line_number);
	stack->n *= tmp->n;
}

/**
 * getDiv - divide the second by the top element of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getDiv(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_DIV, line_number);
		exit(EXIT_FAILURE);
	}
	if (stack->n == 0)
	{
		dprintf(STDERR_FILENO, ERR_ZERO, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, line_number);
	stack->n /= tmp->n;
}

/**
 * getMod - modulo the second by the top element of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getMod(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t **tmp;

	len = dlistint_len(stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ERR_MOD, line_number);
		exit(EXIT_FAILURE);
	}
	if (stack->n == 0)
	{
		dprintf(STDERR_FILENO, ERR_ZERO, line_number);
		exit(EXIT_FAILURE);
	}
	tmp->n = stack->n;
	pop(stack, line_number);
	stack->n %= tmp->n;
}
