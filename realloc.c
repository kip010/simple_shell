#include "shell.h"

/**
 **_memset - for filling memory with  constant byte
 *@s: pointer that points memory area
 *@b: byte that fills *s with
 *@n: amount of the bytes to be filled
 *Return: s a pointer to  memory area or areas
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}

/**
 * ffree - it frees string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **i = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(i);
}

/**
 * _realloc - block of memory reallocation
 * @ptr: pointer to the previous malloc'ated block of memory
 * @old_size: size of byte of previous memory block
 * @new_size: size of byte of new block
 *
 * Return: pointer to the old block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
