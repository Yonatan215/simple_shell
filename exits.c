#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: source string
 * @n: the amout of characters to be copied
 * Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, x;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		x = i;
		while (x < n)
		{
			dest[x] = '\0';
			x++;
		}
	}
	return (s);
}
/**
 * _strncat - concatenated two string
 * @dest: first string
 * @src: second string
 * @n: the amount of bytes to be maximally used
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, x;
	char *s = dest;

	i = 0;
	x = 0;
	/*Move dest pointer to end of string*/
	while (dest[i] != '\0')
		i++;
	/*Copy src to dest until n characters hv been copied*/
	/*or the end of src is reached*/
	while (src[x] != '\0' && x < n)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	if (x > n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - locates a character in a string
 * @s: string to be parsed
 * @c: character to look for
 * Return: (s) pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
