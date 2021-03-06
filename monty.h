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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIMITERS " \t\r\n\v\f"

#define USAGE "USAGE: monty file\n"
#define ERR_FILE "Error: Can't open file %s\n"
#define ERR_OPCODE "L%d: unknown instruction %s\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_SWAP "L%d: can't swap, stack too short\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_SUB "L%d: can't sub, stack too short\n"
#define ERR_DIV "L%d: can't div, stack too short\n"
#define ERR_MUL "L%d: can't mul, stack too short\n"
#define ERR_ZERO "L%d: division by zero\n"
#define ERR_MOD "L%d: can't mod, stack too short\n"
#define ERR_PCHAR "L%d: can't pchar, stack empty\n"
#define ERR_NOCHAR "L%d: can't pchar, value out of range\n"

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

typedef stack_t dlistint_t;

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
 * @lineN: line number
 * @cmd: command
 * @value: value
 * @queue: 1 if queue
 * Description: global struct with program info
 */
typedef struct data_s
{
	FILE *fp;
	stack_t *stack;
	char *line;
	unsigned int lineN;
	char *cmd;
	char *value;
	int queue;
} data_t;

data_t data;

/* monty.c module */
int main(int argc, char **argv);
void initData(void);
void initialChk(int ac, char *file);
void parse(void);

/* opcode.c module */
void getOp(void);
void freeStack(void);
void freeAll(void);

/* getOps.c module */
void getPush(stack_t **stack, unsigned int line_number);
void getPall(stack_t **stack, unsigned int line_number);
void getQueue(stack_t **stack, unsigned int line_number);
void getStack(stack_t **stack, unsigned int line_number);
void getPint(stack_t **stack, unsigned int line_number);

/* ops.c module*/
void getAdd(stack_t **stack, unsigned int line_number);
void getSub(stack_t **stack, unsigned int line_number);
void getMul(stack_t **stack, unsigned int line_number);
void getDiv(stack_t **stack, unsigned int line_number);
void getMod(stack_t **stack, unsigned int line_number);

/* ops2.c module*/
void getPchar(stack_t **stack, unsigned int line_number);
void getPstr(stack_t **stack, unsigned int line_number);
void getPop(stack_t **stack, unsigned int line_number);
void getSwap(stack_t **stack, unsigned int line_number);

/* ops3.c module*/
void getNop(stack_t **stack, unsigned int line_number);
void getRotl(stack_t **stack, unsigned int line_number);
void getRotr(stack_t **stack, unsigned int line_number);

/* stack.c module */
int is_num(char *str);
int push(int n);

/* dlfcts.c module */
size_t print_dlistint(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

#endif
