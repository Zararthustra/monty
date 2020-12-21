#ifndef MONTY_H
#define MONTY_H

/* standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>

#define DELIMITERS " \t\r\n\v\f"
#define USAGE "USAGE: monty file\n"
#define ERR_FILE "Error: Can't open file %s\n"
#define ERR_OPCODE "L%d: unknown instruction %s\n"
#define ERR_MALLOC "Error: malloc failed\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - global info structure
 * @fp: file pointer
 * @stack: pointer to stack
 * @line: pointer to the line
 * @lineN: number of lines
 * @queue: 1 if queue
 * Description: global struct with program info
 */
typedef struct data_s
{
	FILE *fp;
	stack_t *stack;
	char *line;
	unsigned int lineN;
	int queue;
} data_t;

extern data_t data;

/* monty.c module */
int main(int argc, char **argv);
void initData(void);
void initialChk(int ac, char *file);
void parse(void);

/* opcode.c module */
void getOp(stack_t **stack, char *op);
void freeStack(stack_t *head);
void freeAll(void);

/* getOps.c module */
void getPall(stack_t **stack, unsigned int lineN);

/* push.c module */
void pushStack(char *value);
void pushQueue(char *value);

#endif