#include "monty.h"

/**
 * free_vglo - funtion that frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo -function that  initializes the global variables
 *
 * @fd:  the file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * check_input -function that  checks if the file exists and whether it can
 * be opened
 *
 * @argc: the argument count
 * @argv: the argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *file_d;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_d = fopen(argv[1], "r");

	if (file_d == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file_d);
}

/**
 * main - the entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file_d;
	size_t size = 256;
	ssize_t num_lines = 0;
	char *lines[2] = {NULL, NULL};

	file_d = check_input(argc, argv);
	start_vglo(file_d);
	num_lines = getline(&vglo.buffer, &size, file_d);
	while (num_lines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		num_lines = getline(&vglo.buffer, &size, file_d);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}
