#include "monty.h"
/**
*isdigit_ - checks whether the argument is a digit
*@s: element to check
*Return: 1 if it is a digit else -1
*/
int isdigit_(const char *s)
{
	if (s == NULL)
		return (-1);
	if (*s == '-')
	{
		s++;
	}
	while (*s)
	{

	if (*s < '0' || *s > '9')
		return (-1);
	s++;
	}
	return (1);
}

/**
 *free_mem - free a linked list
 *@stack: pointer to stack
 *
 *
 */
void free_mem(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}
/**
 *swap - swap the top two elements of a stack
 *@stack: pointer to stack
 *@line_number: line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top_val;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top_val = (*stack)->next->n;
		(*stack)->next->n = (*stack)->n;
		(*stack)->n = top_val;

	}

}

/**
 *add - adds the top two elements of a stack
 *@stack: pointer to stack
 *@line_number: line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr,  "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->next->n + (*stack)->n;
		temp = (*stack)->next;
		temp->n = sum;
		free(*stack);
		(*stack) = temp;

	}

}

/**
 *nop - does nothing
 *@stack: pointer to stack
 *@line_number: file line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
