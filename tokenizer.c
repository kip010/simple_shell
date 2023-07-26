#include "shell.h"

/**
 * **strtow - split  string to words. Repeated delimiters ignored
 * @str: input str
 * @d: delimeter str
 * Return: pointer to array of strings or on failure NULL
 */

char **strtow(char *str, char *d)
{
	int a, j, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[a], d))
			a++;
		l = 0;
		while (!is_delim(str[a + l], d) && str[a + l])
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[a++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - split str into words
 * @str: input str
 * @d: delimeter
 * Return: a pointer to array of strings, on failure NULL
 */
char **strtow2(char *str, char d)
{
	int a, j, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, j = 0; j < numwords; j++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		l = 0;
		while (str[a + l] != d && str[a + l] && str[a + l] != d)
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[a++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
