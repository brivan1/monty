#include "monty.h"
void global_val(void);
int value;
/**
 *main - program Entry point.
 *@ac:  arguments count.
 *@argv: arguments vector.
 *Return: nothing.
 */

int main(int ac, char *argv[])
{

	if (ac != 2)
		usage_err();
	else
		execute(argv);

	exit(EXIT_SUCCESS);
}
