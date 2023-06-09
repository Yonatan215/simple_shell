#include "shell.h"
/**
 * get_environ_info - a program function that gets environment
 * information
 * @info: information input
 * Return: environ info
 */
char **get_environ_info(info_t *info)
{
	if (info->environ == NULL || !info->env_swap)
	{
		info->environ = list_strings(info->env);
		info->env_swap = 0;
	}
	return (info->environ);
}
/**
 * get_unsetenv - a program function that unsets environment variable
 * @info: information input
 * @temp: variable input character
 * Return: unset environment
 */
int get_unsetenv(info_t *info, char *temp)
{
	list_t *node = info->env;
	size_t a = 0;
	char *b;

	if (node == NULL || temp == NULL)
		return (0);
	for (node = info->env; node != NULL; node = node->next)
	{
		b = starts_with(node->str, temp);
		if (b && *b == '=')
		{
			info->env_swap = delete_node_idx(&(info->env), a);
			a = 0;
			node = info->env;
			continue;
		}
		a++;
	}
	return (info->env_swap);
}
/**
 * get_setenv - a program function that sets ensironment variable
 * @info: information
 * @temp: variable character
 * @eval: environment value
 * Return: set environment variable
 */
int get_setenv(info_t *info, char *temp, char *eval)
{
	char *b, *buffer = NULL;
	list_t *node;

	if (eval == NULL || temp == NULL)
		return (0);

	buffer = malloc(_strlen(temp) + _strlen(eval) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, temp);
	_strcat(buffer, "=");
	_strcat(buffer, eval);
	node = info->env;
	do {
		b = starts_with(node->str, temp);
		if (b && *b == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_swap = 1;
			return (0);
		}
		node = node->next;
	} while (node);

	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_swap = 1;
	return (0);
}
