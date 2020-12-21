#include "monty.h"

/**
 * getPush - pushes an element to stack
 * @data: shared data
 */
void getPush(stack_t **stack, unsigned int line_number)
{
/*
	if (!is_num(data.value))
	{
		dprintf(STDERR_FILENO, ERR_PUSH, data.lineN);
		freeAll(data);
		exit(EXIT_FAILURE);
	}
*/
	if (!push(atoi(data.value)))
	{
		dprintf(STDERR_FILENO, ERR_MALLOC);
		freeAll(data);
		exit(EXIT_FAILURE);
	}
}

/**
 * getPall - prints all the elements of a stack_t list
 * @data: shared data
 */
void getPall(stack_t **stack, unsigned int line_number)
{
	print_dlistint(*stack);
}

