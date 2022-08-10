#include "main.h"

int _printf(const char *format, ...)
{
va_list ap;
unsigned int i, j, l;
int count = 1;
char * arg;

i = j = l = 0;
for (i=0;i < strlen(format);i++)
{
if (format[i] == '%')
l++;
}
i = 0;
va_start(ap, 1 - 1);
while(i < strlen(format))
{
if (i == 0)
{
if (format[i] != '%')
write(1,&format[i],1);
}
else
{
if(format[i - 1] != '%' && format[i] != '%')
{
write(1,&format[i],1);
count++;
}
else if(format[i - 1] == '%' && isalnum(format[i]))
{
if(format[i] == 'c')
{
_CHAR_PR(va_arg(ap, int));
}
else if (format[i] == 's')
{
arg = va_arg(ap,char *);
_STRING_PR(arg);
}
else if (format[i] == 'S')
{
arg = va_arg(ap,char *);
_UNSTRING_PR(arg);
}
else if (format[i] == 'i' || format[i] == 'u')
{
unsigned int arg;
arg = va_arg(ap, unsigned int);
_UINT_PR(arg);
}
else if (format[i] == 'b')
{
unsigned int arg = va_arg(ap, unsigned int);
_BYTE_PR(arg);
}
else if (format[i] == 'x')
{
unsigned int arg;
arg = va_arg(ap, unsigned int);
_hex_PR(arg);
}
else if (format[i] == 'X')
{
unsigned int arg;
arg = va_arg(ap, unsigned int);
_HEX_PR(arg);
}
else if (format[i] == 'o')
{
unsigned long arg;
arg = va_arg(ap, unsigned long);
_OCTAL_PR(arg);
}
else if (format[i] == 'd')
{
int arg = 0;
arg = va_arg(ap, int);
_SINT_PR(arg);
}
else if (format[i] == 'p')
{
char *arg;
arg = (char *)va_arg(ap,void *);
_ADDRESS_PR(arg);
}
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
