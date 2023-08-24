#include "monty.h"

/**
 * _queue - function that sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the list
 * @cline: line number;
 * Return: no return
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - function that sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the list
 * @cline: line number;
 * Return: no return
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - function that adds the top two elements of the stack
 *
 * @doubly: head of the list
 * @cline: line number
 * Return: no return
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int j = 0;
	stack_t *node = NULL;

	node = *doubly;

	for (; node != NULL; node = node->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	node = (*doubly)->next;
	node->n + = (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - function that does not do anythinhg
 *
 * @doubly: head of the list
 * @cline: line number
 * Return: no return
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int j = 0;
	stack_t *node = NULL;

	node = *doubly;

	for (; node != NULL; node = node->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	node = (*doubly)->next;
	node->n -= (*doubly)->n;
	_pop(doubly, cline);
}
