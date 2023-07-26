#include "shell.h"

/**
 * bfree - makes address NULL and frees the pointer
 * @ptr: the address of the pointer to be free
 *
 * Return: if freed 1, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
