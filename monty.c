#include "monty.h"

data_t data = INIT_DATA;

/**
 * main - entry point
 * @argc: argument count
 * @argv: list of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	initialChk(argc, argv[1]);
	parse();
/*
	freeAll();
*/
	return (EXIT_SUCCESS);
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
	char *op, *value;

	while ((read = getline(&(data.line), &size, data.fp)) != -1)
	{
		op = strtok(data.line, DELIMITERS);
		data.cmd = op;
		data.value = strtok(NULL, " ");
		getOp();
		data.lineN++;
	}
}
