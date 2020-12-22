#include "monty.h"

/**
 * getAdd - adds the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getAdd(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *cur;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_ADD, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	cur = tmp->next;
	cur->n += tmp->n;
	getPop(stack, line_number);
}

/**
 * getSub - substracts the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getSub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_SUB, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp = tmp->next;
	tmp->n -= n;
	getPop(stack, line_number);
}

/**
 * getMul - multiplies the top two elements of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getMul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_MUL, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp = tmp->next;
	tmp->n *= n;
	getPop(stack, line_number);
}

/**
 * getDiv - divide the second by the top element of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getDiv(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_DIV, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, ERR_ZERO, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp = tmp->next;
	tmp->n /= n;
	getPop(stack, line_number);
}

/**
 * getMod - modulo the second by the top element of the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */

void getMod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, ERR_MOD, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, ERR_ZERO, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp = tmp->next;
	tmp->n %= n;
	getPop(stack, line_number);
}
