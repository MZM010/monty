#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void err(int code_err, ...);
void string_err(int code_err, ...);
void more_err(int code_err, ...);
int parse_line(char *buffer, int line_number, int format);
int main(int argc, char *argv[]);
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);

void addToStack(stack_t **newNode, unsigned int ln);
void printStack(stack_t **stack, unsigned int line_num);
void popTop(stack_t **stack, unsigned int line_number);
void printTop(stack_t **stack, unsigned int line_number);

void Nop(stack_t **stack, unsigned int line_num);
void swapNodes(stack_t **stack, unsigned int line_num);
void addNodes(stack_t **stack, unsigned int line_num);

void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int ln);

void open_file(char *file);
void read_file(FILE *jv);

void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
void call_fun(op_func, char *, char *, int, int);

#endif
