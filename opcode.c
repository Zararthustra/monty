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
		{"pint", getPint},
		{"pop", getPop},
		{"swap", getSwap},
		{"add", getAdd},
		{"sub", getSub},
/*		{"pchar", getPchar},
		{"pstr", getPstr},
		{"pint", getPint},
		{"pop", getPop},
		{"mul", getMul},
		{"div", getDiv},
		{"mod", getMod},
		{"rotl", getRotl},
		{"rotr", getRotr},
*/
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
 */
void freeStack(void)
{
	stack_t *tmp, *current = data.stack;

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
	freeStack();
}
