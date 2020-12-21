#include "monty.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: the head of a double linked list.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}
	return (nodes);
}

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to the list
 * @n: value
 * Return: pointer to the new node or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
		return (new);
	}

	*head = new;
	new->next = NULL;
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: pointer to the list
 * @n: value
 * Return: pointer to the new node or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *node;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
		return (new);
	}

	*head = new;
	new->prev = NULL;
	return (new);
}

/**
 * get_dnodeint_at_index - returns the nth node of a linked list
 * @head: head of the list
 * @index: index of the node to get
 * Return: the node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int idx = 0;

	if (!head)
		return (NULL);

	while (idx < index && head)
	{
		head = head->next;
		idx++;
	}
	if (idx == index)
		return (head);
	return (NULL);
}
