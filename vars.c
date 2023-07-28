#include "shell.h"

/**
 * is_chain - test current character in buffer is chain delimeter
 * @info: parameter structure
 * @buf: character buffer
 * @p: an address of current position in buffer
 *
 * Return: if chain delimeter 1, else return 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks to continue chaining based on previous status
 * @info: parameter structure
 * @buf: character buf
 * @p: an address of current pos in buffer
 * @a: the starting position in buffer
 * @len: length of buffer
 *
 * Return: Null
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t a, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[a] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[a] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces alias in tokenized str
 * @info: parameter structure
 *
 * Return: if replaced 1, else return 0
 */
int replace_alias(info_t *info)
{
	int a;
	list_t *node;
	char *p;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replace vars in tokenized str
 * @info: parameter structure
 *
 * Return: if replaced 1, else return 0
 */
int replace_vars(info_t *info)
{
	int a = 0;
	list_t *node;

	for (a = 0; info->argv[a]; a++)
	{
		if (info->argv[a][0] != '$' || !info->argv[a][1])
			continue;

		if (!_strcmp(info->argv[a], "$?"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[a][1], '=');
		if (node)
		{
			replace_string(&(info->argv[a]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - for replacing string
 * @old: for replacing string
 * @new: new string address
 *
 * Return: if replaced 1, else 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
