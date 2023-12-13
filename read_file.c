#include "monty.h"
/**
 * push_to_stack - push element to the stack
 * @value: value of the node
 * @head: the head of the linked list
 * Return: the head
 */

stack_t *push_to_stack(stack_t *head, char *value)
{
	stack_t *new = NULL;
	int val;

	val = atoi(value);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->n = val;
	new->prev = NULL;
	new->next = head;
	if (head)
		head->prev = new;
	head = new;
	return (head);
}
/**
 * pall - print all
 * @head: the head of the linked list
 */

void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
/**
 * check_function - check the opcode
 * @buffer: the buffer that contain the line
 * @head: the head of the linked list
 * Return: the head
 */

stack_t *check_function(char *buffer, stack_t **head)
{
	char *tokenize_value, *value;

	if (!buffer)
		fprintf(stderr, "Error: malloc failed\n");
	tokenize_value = strtok(buffer, " \n\t");
	if (tokenize_value != NULL)
	{
		value = strtok(NULL, " ");
	}

	if (strcmp("push", tokenize_value) == 0)
	{
		*head = push_to_stack(*head, value);
	}

	if (strcmp("pall", tokenize_value) == 0)
	{
		pall(*head);
	}
	if (strcmp("pint", tokenize_value) == 0)
	{
		pint(*head);
	}
	return (*head);
}
/**
 * free_stack - free stack
 * @node: the head of the linked list
 */
void free_stack(stack_t *node)
{
	stack_t *temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
/**
 * pint - print element
 * @head: the head of the linked list
 */
void pint(stack_t *head)
{
	if (!head)
	{
		fprintf(stderr, "L1 can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
