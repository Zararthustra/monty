#include "monty.h"

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
 * initData - initialize global variables
 *
 */
void initData(void)
{
	data.fp = NULL;
	data.stack = NULL;
	data.line = NULL;
	data.lineN = 1;
	data.cmd = NULL;
	data.value = NULL;
	data.numW = 0;
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
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}

	data.fp = fopen(file, "r");
	if (!(data.fp))
	{
		dprintf(STDERR_FILENO, ERR_FILE, file);
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
	char *op = NULL;

	while ((read = getline(&(data.line), &size, data.fp)) != -1)
	{
		if (read == 0)
			continue;
		op = strtok(data.line, DELIMITERS);
		if (!op ||*op == '#' || *op == '\n')
		{
			data.lineN++;
			continue;
		}
		data.cmd = op;
		data.value = strtok(NULL, DELIMITERS);
		getOp();
		data.lineN++;
	}
}
