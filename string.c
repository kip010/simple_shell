#include "shell.h"

/**
 * _strlen - returns length of  string
 * @s: string whose length is to be checked
 *
 * Return: int length of a string
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - lexicogarphic comparison of two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: if s1 < s2 negative,if s1 > s2 positive, if s1 == s2 zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check needle if starts with haystack
 * @haystack: the str to search
 * @needle: the substr to find
 *
 * Return: the address of a next char of a haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - links two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
