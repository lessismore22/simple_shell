#include "shell.h"

/**
 * get_environ - returns string array copy of our environ
 * @info: structure containing potential arguments used to maintain
 * constant function prototype
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * rem_env - remove environment variable
 * @info: structure containing potential arguments used to maintain
 * constant function prototype
 *  Return: 1 or 0
 * @var: string env var property
 */

int rem_env(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *pi;

	if (!node || !var)
		return (0);

	while (node)
	{
		pi = starts_with(node->str, var);
		if (pi && *pi == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _getenv - Initialize new environment variable or modify
 * @info: structure containing potential arguments used to maintain
 * constant function prototype
 * @var: string env var property
 * @value: string env var value
 *  Return: Always 0
 */

int _getenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *pi;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;
	while (node)
	{
		pi = starts_with(node->str, var);
		if (pi && *pi == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
