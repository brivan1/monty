#include "monty.h"


/**
 *push - function to insert into the stack.
 *@stack: pointer to top of the stack
 *@line_number: data to i inset into the stack.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	(void)line_number;

	newnode = (stack_t *)malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = value;
	if (*stack == NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		(*stack) = newnode;
	}
	else
	{
		(*stack)->prev = newnode;
		newnode->next = *stack;
		(*stack) = newnode;
	}
}

/**
 *pall - prints all elements in a stack
 *@stack: pointer to top of the stack
 *@line_number: line number of the instruction in a file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}

}

/**
 *pop - removes the top element from a stack
 *@line_number: file line number
 *@stack: pointer to stack
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp)
			temp->prev = NULL;
		(*stack) = temp;
	}

}


/**
 *pint - prints the value at the top of the stack
 *@line_number: instruction line number on the monty file
 *@stack: pointer to stack
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		
