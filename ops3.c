#include "monty.h"

/**
 * getNop - doesnt do anything.
 * @stack: head of the stack
 * @line_number: line number
 * Return: void
 */
void getNop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * getRotl - rotates the stack to the top.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getRotl(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp = *stack, *cur;

	(void)line_number;

	if (tmp)
	{
		cur = tmp->next;
		n = tmp->n;
		while (tmp->next)
		{
			tmp->n = cur->n;
			tmp = cur;
			cur = tmp->next;
		}
		tmp->n = n;
	}
}

/**
 * getRotr -  rotates the stack to the rear.
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void getRotr(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp = *stack, *cur;

	(void)line_number;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		cur = tmp->prev;
		n = tmp->n;
		while (tmp->prev)
		{
			tmp->n = cur->n;
			tmp = cur;
			cur = tmp->prev;
		}
		tmp->n = n;
	}
}
