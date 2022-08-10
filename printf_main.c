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

        //////////////////////////////////////////////

        else if (format[i] == 's')
        {
            arg = va_arg(ap,char *);
            _STRING_PR(arg);
        }

        ////////////////////////////////////////////////

        else if (format[i] == 'S')
        {
            arg = va_arg(ap,char *);
            _UNSTRING_PR(arg);
        }

        ////////////////////////////////////////////////

        else if (format[i] == 'i' || format[i] == 'u')
        {
            unsigned int ar , q = 0 , r;
            ar = va_arg(ap, unsigned int);

            while (ar != 0)
            {
            r = ar % 10;
            q = q * 10 + r;
            ar /= 10;
            }
            ar = q;
            while(ar != 0)
            {
            r = (ar % 10) + '0';
            ar = ar / 10;
            write(1,&r,1);
            count++;
            }
        }

        //////////////////////////////////////////////

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
            int ar = 0 , q = 0 , r = 0;
            ar = va_arg(ap, int);

            if (ar < 0)
            {
                ar = -1 * ar;
                write(1,"-",1);
            }
            while (ar != 0)
            {
            r = ar % 10;
            q = q * 10 + r;
            ar /= 10;
            }
            ar = q;
            while(ar != 0)
            {
            r = (ar % 10) + '0';
            ar = ar / 10;
            write(1,&r,1);
            count++;
            }
        }
        else if (format[i] == 'p')
        {
            char *ar, *c;

            ar = (char *)va_arg(ap,void *);
            c = malloc((strlen(ar) + 2)*sizeof(char));
            printf("%du", sizeof(ar));
            for(j=0;j < sizeof(ar);j++)
            {
                write(1,&ar[j],1);
                count++;
            }
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
