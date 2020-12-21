#include "monty.h"

/**
 * getOp - finds and executes a function based on op
 * @stack: double pointer to head of stack
 * @op: command to be executed
 */
void getOp(stack_t **stack, char *op)
{
	int idx;
	char *command;
	instruction_t opDict[] = {
		{"pall", getPall},
		{NULL, NULL}
	};

	command = strtok(op, "\n");
	for (idx = 0; opDict[idx].opcode; idx++)
		if (strcmp(command, opDict[idx].opcode) == 0)
		{
			opDict[idx].f(stack, data.lineN);
			return;
		}
	dprintf(STDERR_FILENO, "L%d: ", data.lineN);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", op);
	freeAll();
	exit(EXIT_FAILURE);
}

/**
 * freeStack - frees a stack_t list
 * @head: pointer to the head of the list
 */
void freeStack(stack_t *head)
{
	stack_t *tmp, *current = head;

	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

/**
 * freeAll - frees all malloc'ed data structures and closes
 * file decriptor
 */
void freeAll(void)
{
	fclose(data.fp);
	free(data.line);
	freeStack(data.stack);
}
