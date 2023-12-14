#include "monty.h"
/**
 * Nop - nothing to be done
 * @stack: pointer to stack
 * @line_num: line number
 *
 * Return: nothing
 */
void Nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
 * swapNodes - swap the 2 top elements of stack
 * @stack: pointer to stack
 * @line_num: line number
 *
 * Return: nothing
 */
void swapNodes(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * addNodes - sum of 2 top of stack
 * @stack: pointer to stack
 * @line_num: line number
 *
 * Return: nothing
 */
void addNodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
