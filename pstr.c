#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @head: pointer to stack head
 * @line_number: number of  line
 *
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	int value;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	value = (*head)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _pstr - print the stack top string
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
		int a = 0;

	(void)line_number;


	while (tmp)
	{
		a = tmp->n;
		if (a == 0 || _isalpha(a == 0))
			break;
		putchar(a);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotate the  stack to the top
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp  = *head;

	int aux = 0;

	if (!line_number || !head || !*head || !(*head)->next)
		return;

	aux = tmp->n;

	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev->n = tmp->n;
	}

	tmp->n = aux;
}

/**
 * _rotr - function to rotate the stack to the bottom
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	int aux = 0;

	if (!line_number || !head || !*head || !(*head)->next)
		return;

	while (tmp->next)
		tmp = tmp->next;

	aux = tmp->n;

	while (tmp->prev)
	{
		tmp = tmp->prev;
		tmp->next->n = tmp->n;
	}

	tmp->n = aux;
}
