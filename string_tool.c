#include "monty.h"
/**
 * print_char - print char
 * @stack: doubly linked list
 * @line_number: line number
 *
 * Return: nothing
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}
/**
 * print_string - print string
 * @stack: linked list
 * @ln: line number
 *
 * Return: nothing
 */
void print_string(stack_t **stack, unsigned int ln)
{
	int ascii;
	stack_t *tmp;
	(void) ln;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}


