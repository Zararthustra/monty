#include "monty.h"

data_t data;

/**
 * main - entry point
 * @argc: argument count
 * @argv: list of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	initData();
	initialChk(argc, argv[1]);
	parse();
	freeAll();
	return (EXIT_SUCCESS);
}

/**
 * initData - initializes data struct
 */
void initData(void)
{
	data.fp = NULL;
	data.stack = NULL;
	data.line = NULL;
	data.lineN = 1;
	data.queue = 0;
}

/**
 * initialChk - validates user input and opens file
 * @ac: argument count
 * @file: name of file to be opened
 */
void initialChk(int ac, char *file)
{
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.fp = fopen(file, "r");
	if (!data.fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
}

/**
 * parse - reads file and processes the commands
 */
void parse(void)
{
	size_t size = 0;
	ssize_t read;
	char *op, *value;

	while ((read = getline(&data.line, &size, data.fp)) != -1)
	{
		op = strtok(data.line, DELIMITERS);
		if (*op == '#')
		{
			data.lineN++;
			continue;
		}
		if (strcmp(op, "push") == 0)
		{
			value = strtok(NULL, DELIMITERS);
			data.lineN++;
			continue;
		}
		getOp(&data.stack, op);
		data.lineN++;
	}
}
