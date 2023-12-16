#include "shell.h"
/**
 * _erratoi - Converts a string to an integer, handling errors.
 *
 * This function converts a string to an integer while checking for potential
 * errors. If the string starts with a '+', it is ignored, and the conversion
 * continues. If any non-numeric character is encountered during conversion,
 * the function returns -1 to indicate an error. If the converted number
 * exceeds INT_MAX, it also returns -1.
 *
 * @s: The string to be converted to an integer.
 * Return: result
 */
int _strtoi(char *s)
{
	int i = 0;
	unsigned long int val = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			val *= 10;
			val += (s[i] - '0');
			if (val > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (val);
}
