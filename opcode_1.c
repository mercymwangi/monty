#include "monty.h"

/**
 * _push - function that pushes an element to the stack
 *
 * @doubly: head of node in list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int l, h;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (h = 0; vglo.arg[h] != '\0'; h++)
	{
		if (!isdigit(vglo.arg[h]) && vglo.arg[h] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	l = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, l);
	else
		add_dnodeint_end(doubly, l);
}

/**
 * _pall - function that prints all values on the stack
 *
 * @doubly: head of the list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *node;
	(void)cline;

	node = *doubly;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * _pint -function  prints the value at the top of the stack
 *
 * @doubly: head of the  list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - function that removes the top element of the stack
 *
 * @doubly: head of the list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *node;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	node = *doubly;
	*doubly = (*doubly)->next;
	free(node);
}

/**
 * _swap - function that swaps the top two elements of the stack
 *
 * @doubly: head of the list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int j = 0;
	stack_t *node = NULL;

	node = *doubly;

	for (; node != NULL; node = node->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	node = *doubly;
	*doubly = (*doubly)->next;
	node->next = (*doubly)->next;
	node->prev = *doubly;
	(*doubly)->next = node;
	(*doubly)->prev = NULL;
}
