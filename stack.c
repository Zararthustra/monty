#include "monty.h"

/**
 * is_num - increments thru str to find num
 * @str: str to check
 * Return: 1 if true, 0 if false
 */
int is_num(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - pushes node to stack (head)
 * @n: int value to be in added node
 * Return: 1 is added 0 otherwise
 **/
int push(int n)
{
	if (data.queue)
		return (!!add_dnodeint_end(&(data.stack), n));
	return (!!add_dnodeint(&(data.stack), n));
}
