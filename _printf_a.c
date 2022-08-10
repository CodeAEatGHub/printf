#include "main.h"
#include <math.h>

/**
 * _ADDRESS_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _ADDRESS_PR(char *arg, int count)
{
	unsigned int j;

	printf("%ld", sizeof(arg));
	for (j = 0 ; j < sizeof(arg) ; j++)
	{
		write(1, &arg[j], 1);
		count++;
	}
	return (count);
}
/**
 * _SINT_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _SINT_PR(int arg, int count)
{
	int q = 0, r = 0;

	if (arg < 0)
	{
		arg = -1 * arg;
		write(1, "-", 1);
		count++;
	}
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
	return (count);
}
/**
 * _OCTAL_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _OCTAL_PR(unsigned long arg, int count)
{
	int i = 0;
	unsigned long p = 0, q = 0, t = 1, r;
	unsigned long *oct;

	oct = malloc((numdigits(arg) + 2) * sizeof(unsigned long));
	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = q;
		else
			r = (q % 8);
		oct[i] = r + '0';
		t = t * 10;
		p = p + ((t / 10) * r);
		q = q / 8;
		i++;
	}
	i--;
	for (; i >= 0 ; i--)
	{
		write(1, &oct[i], 1);
		count++;
	}
	free(oct);
	return (count);
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
			{
				write(1, &format[i], 1);
				if ((int)format[i] >= 32 && (int)format[i] < 127)
					count++;
			}
		}
		else
		{
			if (format[i - 1] != '%' && format[i] != '%')
			{
				write(1, &format[i], 1);
				if ((int)format[i] >= 32 && (int)format[i] < 127)
					count++;
			}
			else if (format[i - 1] == '%' && isalnum(format[i]))
			{
				if (format[i] == 'c')
					count = _CHAR_PR(va_arg(ap, int), count);
				else if (format[i] == 's')
					count = _STRING_PR(va_arg(ap, char *), count);
				else if (format[i] == 'S')
					count = _UNSTRING_PR(va_arg(ap, char *), count);
				else if (format[i] == 'p')
					count = _ADDRESS_PR(va_arg(ap, char *), count);
				else if (format[i] == 'i' || format[i] == 'u')
					count = _UINT_PR(uiarg = va_arg(ap, unsigned int), count);
				else if (format[i] == 'b')
					count = _BYTE_PR(uiarg = va_arg(ap, unsigned int), count);
				else if (format[i] == 'x')
					count = _hex_PR(uiarg = va_arg(ap, unsigned int), count);
				else if (format[i] == 'X')
					count = _HEX_PR(uiarg = va_arg(ap, unsigned int), count);
				else if (format[i] == 'o')
					count = _OCTAL_PR(uarg = va_arg(ap, unsigned int), count);
				else if (format[i] == 'd')
					count = _SINT_PR(iarg = va_arg(ap, int), count);
			}
			else if (format[i] != '%' && format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		i++;
	}
	va_end(ap);
	return (count);
}
