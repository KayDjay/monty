#include "monty.h"
/**
 * _push - push an element to the stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = opcode.arg;
	top->next = *head;
	top->prev = NULL;
	if (*head != NULL)
		(*head)->prev = top;
	*head = top;
}

/**
 * _pall - print all the value on the stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _pall(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - print the value at top of the stack
 * @head: pointer to stack head
 * @line_number: number of line
 *
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * _pop - remove top element of the stack
 *@head: pointer to stack head
 *@line_number: number of line
 *Return: void
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *n = *head;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*head = n->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(n);
}

/**
 * free_dlistint - free a list
 * @head: pointer to stack head
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
