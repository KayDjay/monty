#include "monty.h"
/**
 * _swap - swap top two of stack
 * @head: pointer to stack head
 * @line_number: number of line
 */

void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *head;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _add - add the top two element of stack
 * @head: pointer to stack head
 * @line_number: number of line
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int sum = 0, a = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		a++;
	}

	if (head == NULL || (*head)->next == NULL || a <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->next->n + (*head)->n;
	_pop(head, line_number);

	(*head)->n = sum;
}

/**
 * _nop - function that does nothing
 * @head: pointer to stack head
 * @line_number: number of line
 */

void _nop(__attribute__ ((unused))stack_t **head,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}


/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
