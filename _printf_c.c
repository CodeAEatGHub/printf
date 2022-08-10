#include "main.h"
#include <math.h>

/**
 * _UINT_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _UINT_PR(unsigned int arg)
{
	int count = 0;
	int q = 0, r = 0;

	while (arg != 0)
	{
		r = arg % 10;
		q = q * 10 + r;
		arg /= 10;
	}
	arg = q;
	while (arg != 0)
	{
		r = (arg % 10) + '0';
		arg = arg / 10;
		write(1, &r, 1);
		count++;
	}
	return (0);
}
/**
 * _STRING_PR - Prints unprintable strings
 *
 * @arg: Input string
 *
 * Return:Success
 */
int _STRING_PR(char *arg)
{
	unsigned int j;
	int count = 1;

	for (j = 0 ; j < strlen(arg) ; j++)
	{
		write(1, &arg[j], 1);
		count++;
	}
	return (0);
}
/**
 * _HEX_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _HEX_PR(unsigned int arg)
{
	unsigned int q = 0, p = 0, t = 1, count = 1;
	int r, i;
	char *c;

	c = malloc((numdigits(arg) + 2) * sizeof(char));
	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 16);
		if (r == 10)
			c[i] = 'A';
		else if (r == 11)
			c[i] = 'B';
		else if (r == 12)
			c[i] = 'C';
		else if (r == 13)
			c[i] = 'D';
		else if (r == 14)
			c[i] = 'E';
		else if (r == 15)
			c[i] = 'F';
		else
			c[i] = r + '0';
		t = t * 100;
		p = p + ((t / 100) * r);
		q = q / 16;
		i++;
	}
	for (i--; i >= 0 ; i--)
	{
		write(1, &c[i], 1);
		count++;
	}
	return (0);
}
