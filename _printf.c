#include "main.h"

/**
 * _ADDRESS_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _ADDRESS_PR(char *arg)
{
	unsigned int l;
	int count = 1, i, j;
	char *c;

	c = malloc((strlen(arg) + 2) * sizeof(char));
	printf("%du", sizeof(arg));
	for (j = 0 ; j < sizeof(arg) ; j++)
	{
		write(1, &arg[j], 1);
		count++;
	}
}
/**
 * _SINT_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _SINT_PR(int arg)
{
	unsigned int l = 0;
	int count = 1, i = 0;
	int q = 0, r = 0;

	if (arg < 0)
	{
		arg = -1 * arg;
		write(1, "-", 1);
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
}
/**
 * _OCTAL_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _OCTAL_PR(unsigned long arg)
{
	unsigned int l = 0;
	int count = 1, i = 0;
	unsigned long p = 0, q = 0, t, r;

	t = ULONG_MAX;
	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 8);
	t = t * 10;
	p = p + ((t / 10) * r);
	q = q / 8;
	printf("%lu\n%lu\n%d\n%lu\n", arg, p, r, (unsigned long)t);
	}
	printf("%d\n%d\n\n", p, t);
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
}
/**
 * _BYTE_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _BYTE_PR(int arg)
{
	unsigned int count, q = 0, p = 0, r, t = 1;

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
}
/**
 * _UNSTRING_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _UNSTRING_PR(char *arg)
{
	unsigned int l;
	int count = 1, i, j;
	int a = 0, c = 0, q = 0, r = 0;

	for (j = 0 ; j < strlen(arg); j++)
	{
		c = (int)arg[j];
		if ((c > 0 && c < 32) || c >= 127)
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			if (c < 15)
				write(1, "0", 1);
			_HEX_PR(c);
		}
		else
			write(1, &arg[j], 1);
		count++;
	}
}
/**
 * _CHAR_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _CHAR_PR(char ar)
{
	write(1, &ar, sizeof(ar));
}
/**
 * _hex_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _hex_PR(unsigned int arg)
{
	unsigned int j = 0, q = 0, count, p = 0, t = 1;
	int r, i = 0;
	char tmp;
	char *c;

	c = malloc((log10(arg) + 2) * sizeof(char));
	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 16);
		switch (r)
		{
			case 10:
				c[i] = 'a';
				break;
			case 11:
				c[i] = 'b';
				break;
			case 12:
				c[i] = 'c';
				break;
			case 13:
				c[i] = 'd';
				break;
			case 14:
				c[i] = 'e';
				break;
			case 15:
				c[i] = 'f';
				break;
			default:
				c[i] = r + '0';
		}
		t = t * 100;
		p = p + ((t / 100) * r);
		q = q / 16;
		i++;
	}
	i--;
	for (; i >= 0 ; i--)
	{
		write(1, &c[i], 1);
	}
}
/**
 * _UINT_PR - Prints value
 *
 * @arg: The value to be printed
 *
 * Return: Success
 */
int _UINT_PR(unsigned int arg)
{
	unsigned int l = 0;
	int count = 0, i = 0;
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
}

int _STRING_PR(char *arg)
{
	unsigned int l;
	int count = 1, i, j;

	for (j = 0 ; j < strlen(arg) ; j++)
	{
		write(1, &arg[j], 1);
		count++;
	}
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
	unsigned int ar, q = 0, p = 0, t = 1;
	int r, i;
	char tmp;
	char *c;

	c = malloc((log10(arg) + 2) * sizeof(char));
	q = arg;
	while (q != 0)
	{
		if (q == 1)
			r = 1;
		else
			r = (q % 16);
		switch (r)
		{
			case 10:
				c[i] = 'A';
				break;
			case 11:
				c[i] = 'B';
				break;
			case 12:
				c[i] = 'C';
				break;
			case 13:
				c[i] = 'D';
				break;
			case 14:
				c[i] = 'E';
				break;
			case 15:
				c[i] = 'F';
				break;
			default:
				c[i] = r + '0';
		}
		t = t * 100;
		p = p + ((t / 100) * r);
		q = q / 16;
		i++;
	}
	i--;
	for (; i >= 0 ; i--)
	{
		write(1, &c[i], 1);
	}
	p = t - 1 - p;
	t = t / 10;
}
/**
 * _printf - Prints value
 *
 * @arg: The value to be printed
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
