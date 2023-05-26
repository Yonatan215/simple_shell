#include "shell.h"

/**
 * _eputs - prints  an input string
 * @str: string to be printed
 */
void _eputs(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_eputchar(str[index]);
		index++;
	}
}

/**
 * _eputchar -writes the character c to stardend error
 * @c: character to print
 * Return: 1 (success), -1 on error
 */
int _eputchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fb
 * @c: character to print
 * @fd: filedescriptor to write to
 * Return: 1 success, -1 otherwise
 */
int _putfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putsfd - display an input string
 * @str: the string to be display
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int m = 0;

	if (!str)
		return (0);

	while (*str)
	{
		m += _putfd(*str++, fd);
	}
	return (m);
}
