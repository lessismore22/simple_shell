#include "shell.h"

/**
 * _myhistory - displays history list, one command per line
 * @info: structure containing potential arguments used to maintain
 * constant function prototype
 *  Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: string alias
 * Return: always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *pi, c;
	int reu;

	p = _strchr(str, '=');
	if (!pi)
		return (1);
	c = *pi;
	*pi = 0;
	reu = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pi = c;
	return (reu);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: string alias
 * Return: always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *pi;

	pi = _strchr(str, '=');
	if (!pi)
		return (1);
	if (!*++pi)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 * Return: always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *pi = NULL, *att = NULL;

	if (node)
	{
		pi = _strchr(node->str, '=');
		for (att = node->str; a <= p; att++)
			_putchar(*att);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin (man alias)
 * @info: structure containing potential arguments used to maintain
 * constant function prototype
 *  Return: always 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *pi = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
