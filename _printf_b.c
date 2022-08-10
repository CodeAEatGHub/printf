#include "main.h"
#include <math.h>

/**
 * _BYTE_PR - Prints value
 *
 * @arg: The value to be printed
 * @count: Number of charcters printed
 *
 * Return: Success
 */
int _BYTE_PR(int arg, int count)
{
	unsigned int q = 0, p = 0, r, t = 1;

	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 2);
		t = t * 10;
		p = p + ((t / 10) * r);
		q = q / 2;
	}
	p = t - 1 - p;
	t = t / 10;
	while (p != 0)
	{
		q = (p / t);
		p = p % t;
		t = t / 10;
		if (q == 9)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		count++;
	}
	return (0);
}
/**
 * _UNSTRING_PR - Prints value
 *
 * @arg: The value to be printed
 * @count: Number of characters printed
 *
 * Return: Success
 */
int _UNSTRING_PR(char *arg, int count)
{
	int c = 0;
	unsigned int j = 0;

	for (j = 0 ; j < strlen(arg); j++)
	{
		c = (int)arg[j];
		if ((c > 0 && c < 32) || c >= 127)
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			count += 2;
			if (c < 15)
			{
				write(1, "0", 1);
				count++;
			}
			_HEX_PR(c, count);
		}
		else
		{
			write(1, &arg[j], 1);
			count++;
		}
	}
	return (count);
}
/**
 * _CHAR_PR - Prints value
 *
 * @ar: The value to be printed
 * @count: Number of charcters printed
 *
 * Return: Success
 */
int _CHAR_PR(char ar, int count)
{
	write(1, &ar, sizeof(ar));
	return (count);
}
/**
 * numdigits - Returns the number of digits in a number
 *
 * @arg: The input number
 * @count: Number of characters printed
 *
 * Return: Success
 */
unsigned int numdigits(unsigned int arg)
{
	unsigned int count, i = arg;

	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}
/**
 * _hex_PR - Prints value
 *
 * @arg: The value to be printed
 * @count: Number of characters printed
 *
 * Return: Success
 */
int _hex_PR(unsigned int arg, int count)
{
	unsigned int q = arg, p = 0, t = 1;
	int r, i = 0;
	char *c;

	c = malloc((numdigits(arg) + 2) * sizeof(char));
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 16);
		if (r == 10)
			c[i] = 'a';
		else if (r == 11)
			c[i] = 'b';
		else if (r == 12)
			c[i] = 'c';
		else if (r == 13)
			c[i] = 'd';
		else if (r == 14)
			c[i] = 'e';
		else if (r == 15)
			c[i] = 'f';
		else
			c[i] = r + '0';
		t = t * 100;
		p = p + ((t / 100) * r);
		q = q / 16;
		i++;
	}
	for (i-- ; i >= 0 ; i--)
	{
		write(1, &c[i], 1);
		count++;
	}
	return (count);
}
