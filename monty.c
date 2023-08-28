#include "monty.h"
void  nothing(void);
opcode_ins opcode;

/**
 * main - main function to monty program
 * @ac: arguments count
 * @av: opcode arguement vector
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *head;

	head = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &head);

	free_dlistint(head);
	return (0);
}

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @head: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **head)
{
	char *line;
	size_t a = 0;
	int line_count = 1;
	instruct_func i;
	int check;
	int read;


	opcode.file = fopen(filename, "r");

	if (opcode.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&opcode.buffer, &a, opcode.file)) != -1)
	{
		line = parse_line(opcode.buffer, head, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		i = operation_cd(line);
		if (i == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		i(head, line_count);
		line_count++;
	}
	free(opcode.buffer);
	check = fclose(opcode.file);
	if (check == -1)
		exit(-1);
}

/**
 * operation_cd -  checks for opcode and returns the correct function
 * @str: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruct_func operation_cd(char *str)
{
	int a;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	a = 0;
	while (instruct[a].f != NULL && strcmp(instruct[a].opcode, str) != 0)
	{
		a++;
	}

	return (instruct[a].f);
}

/**
 * _number - function to check all element is number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int _number(char *str)
{
	unsigned int a;

	if (str == NULL)
		return (0);
	a = 0;
	while (str[a])
	{
		if (str[0] == '-')
		{
			a++;
			continue;
		}
		if (!isdigit(str[a]))
			return (0);
		a++;
	}
	return (1);
}

/**
 * parse_line - function to parse a line and argument
 * @line: the line to be parsed
 * @head: pointer to stack head
 * @line_number: number of line
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **head, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)head;
	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (_number(arg) == 1 && arg != NULL)
		{
			opcode.arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
