#include "monty.h"
/**
 *pstr - prints string give the ascii value
 *@stack: pointer to stack
 *@line_number: line number on file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	char character;
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	if (!(*stack))
	{
		printf("\n");
		/*exit(EXIT_FAILURE);*/
	}
	else
	{
		while (temp != NULL)
		{
			if ((temp)->n <= 0 || (temp)->n > 127)
				break;

			character = (char)temp->n;
			temp = temp->next;
			printf("%c", character);
		}
		printf("\n");
	}
}


/**
 *rotl - rotates elements in a stack to the left
 *@stack: pointer to stack
 *@line_number: line number of the instruction
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int rot_val;
	stack_t *temp;

	(void)line_number;

	if ((*stack)->next == NULL)
		exit(EXIT_SUCCESS);

	temp = (*stack);
	rot_val = (*stack)->n;
	while ((*stack) != NULL)
	{
		(*stack)->n = (*stack)->next->n;
		if ((*stack)->next->next == NULL)
		{
			(*stack)->next->n = rot_val;
			(*stack) = temp;
			break;
		}

		(*stack) = (*stack)->next;

	}
}
