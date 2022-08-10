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
/**
 * _printf - Prints value
 *
 * @format: The value to be printed
 *
 * Return: Success
 */

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int uiarg = 0, i, j, l;
	unsigned long uarg = 0;
	int iarg = 0, count = 1;

	i = j = l = 0;
	for (i = 0 ; i < strlen(format); i++)
	{
		if (format[i] == '%')
			l++;
	}
	i = 0;
	va_start(ap, 1 - 1);
	while (i < strlen(format))
	{
		if (i == 0)
		{
			if (format[i] != '%')
				write(1, &format[i], 1);
		}
		else
		{
			if (format[i - 1] != '%' && format[i] != '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else if (format[i - 1] == '%' && isalnum(format[i]))
			{
				if (format[i] == 'c')
					_CHAR_PR(va_arg(ap, int));
				else if (format[i] == 's')
					_STRING_PR(va_arg(ap, char *));
				else if (format[i] == 'S')
					_UNSTRING_PR(va_arg(ap, char *));
				else if (format[i] == 'p')
					_ADDRESS_PR(va_arg(ap, char *));
				else if (format[i] == 'i' || format[i] == 'u')
					_UINT_PR(uiarg = va_arg(ap, unsigned int));
				else if (format[i] == 'b')
					_BYTE_PR(uiarg = va_arg(ap, unsigned int));
				else if (format[i] == 'x')
					_hex_PR(uiarg = va_arg(ap, unsigned int));
				else if (format[i] == 'X')
					_HEX_PR(uiarg = va_arg(ap, unsigned int));
				else if (format[i] == 'o')
					_OCTAL_PR(uarg = va_arg(ap, unsigned int));
				else if (format[i] == 'd')
					_SINT_PR(iarg = va_arg(ap, int));
			}
			else if (format[i] != '%' && format[i] == '%')
			{
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
