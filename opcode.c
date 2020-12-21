#include "monty.h"

/**
 * getOp - finds and executes a function based on op
 */
void getOp(void)
{
	int idx;

	instruction_t opDict[] = {
		{"push", getPush},
		{"pall", getPall},
		{NULL, NULL}
	};

	for (idx = 0; opDict[idx].opcode; idx++)
		if (strcmp(data.cmd, opDict[idx].opcode) == 0)
		{
			opDict[idx].f(&data.stack, data.lineN);
			return;
		}
	dprintf(STDERR_FILENO, ERR_OPCODE, data.lineN, data.cmd);
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
void freeAll(data_t *data)
{
	fclose(data->fp);
	free(data->line);
	freeStack(data->stack);
}
