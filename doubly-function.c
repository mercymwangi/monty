#include "monty.h"

/**
 *add_dnodeint_end - functions that adds a node at the end of a doubly list
 *@head: first node
 *@n: size of data
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *node;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	/*first time*/
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	node = *head;
	while (node->next)
		node = node->next;
	temp->next = node->next;
	temp->prev = node;
	node->next = tmp;
	return (node->next);
}

/**
 *add_dnodeint - afunction that add a note at the start of the doubly link list
 *@head: first node
 *@n:size of data
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	/*first time*/
	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - function that frees the doubly linked list
 *
 * @head: head of the node
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
