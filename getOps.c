#include "monty.h"

/**
 * getPush - pushes an element to stack
 * @stack: head of the stack
 * @line_number: line number
 * Return: void
 */
void getPush(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (!is_num(data.value))
	{
		dprintf(STDERR_FILENO, ERR_PUSH, line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}

	if (!push(atoi(data.value)))
	{
		dprintf(STDERR_FILENO, ERR_MALLOC);
		freeAll();
		exit(EXIT_FAILURE);
	}
}

/**
 * getPall - prints all the elements of a stack_t list
 * @stack: head of the stack
 * @line_number: line number
 * Return: void
 */
void getPall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_dlistint(*stack);
}

