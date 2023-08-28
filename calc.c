#include "monty.h"

/**
 * _sub - sub top of stack by second top stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int sub = 0, a = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		a++;
	}

	if (head == NULL || (*head)->next == NULL || a <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*head)->next->n - (*head)->n;
	_pop(head, line_number);

	(*head)->n = sub;
}

/**
 * _mul - multiplies the 2nd top element with top of the stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _mul(stack_t **head, unsigned int line_number)
{
	int aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*head)->n;
		_pop(head, line_number);
		(*head)->n *= aux;
	}
}

/**
 * _div - div top of stack by second top stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _div(stack_t **head, unsigned int line_number)
{
	int div = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*head)->n;
		_pop(head, line_number);
		(*head)->n /= div;
	}
}

/**
 * _mod - second top element by the top of stack
 * @head: pointer to stack head
 * @line_number: number of line
 */
void _mod(stack_t **head, unsigned int line_number)
{
	int mod = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(opcode.buffer);
		fclose(opcode.file);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*head)->n;
		_pop(head, line_number);
		(*head)->n %= mod;
	}
}
