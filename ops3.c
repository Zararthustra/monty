#include "monty.h"

/**
 * rotl - 
 *
 *
 *
 */

void rotl(stack_t **stack, unsigned int lineN)
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
 * rotr - 
 *
 *
 *
 */

void rotr(stack_t **stack, unsigned int lineN)
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
