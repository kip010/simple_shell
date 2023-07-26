#include "shell.h"

/**
 * Interactive - Checks if the shell is in interactive mode.
 * @info: A pointer to the info_t structure.
 *
 * Return: True if the Shell is in interactive mode. Otherwisse False.
 */

int interactive(info_t *info)
{
	return isatty(STDIN_FILENO);
}



/**
 * is_delim - checksif a character is delimiter.
 * @c: The character to checks.
 * @delim: The delimiter string,
 *
 * Return: True if the character is a delimiter. Otherwise False.
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return 1;
	}O[O
	return 0;
}


/**
 * _isalpha - checks for an alphabetic character.
 * @c: The character to checks.
 *
 * Return: True if c is alhabetic, Otherwise False.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	else
		return 0;
}


/**
 * _atoi - Convert a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted number if vaild. 0 if no number in the string.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	output = (sign == -1) ? -result : result;
	return output;
}
