#include "monty.h"

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


void pall(stack_t *head)
{
    while(head != NULL)
    {
        printf("%d\n", head->n);
        head = head->next;
    }
}

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

void free_stack(stack_t *node)
{
    stack_t *temp;

    while(node)
    {
        temp = node->next;
        free(node);
        node = temp;
    }
}

void pint(stack_t *head)
{
    int i = 1;
    if (!head){
        fprintf(stderr, "L%d: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
    i++;
    printf("%d\n", head->n);
}
