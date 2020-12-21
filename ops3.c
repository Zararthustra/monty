#include "monty.h"

/**
 * getRotl - rotates the stack to the top.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getRotl(stack_t **stack, unsigned int line_number)
{
	stack_t **tmp;

	(void)lineN;
	tmp = stack;
	while (stack)
	{
		stack->n = stack->next->n;
		stack = stack->next;
	}
	stack = tmp;
	stack->next = NULL;
}

/**
 * getRotr -  rotates the stack to the rear.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getRotr(stack_t **stack, unsigned int line_number)
{
	stack_t **tmp;

	(void)lineN;
	while (stack)
		stack = stack->next;
	tmp = stack;
	while (stack)
	{
		stack->n = stack->prev->n;
		stack = stack->prev;
	}
	stack = tmp;
	stack->prev = NULL;
}
