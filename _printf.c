#include "stdarg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include "main.h"
//////////////////////////////////////////////////////////////////
int _ADDRESS_PR(const char *format,...)
{
    va_list ap;
    unsigned int l;
    int count = 1, i, j;
    char * arg;

    i = l = 0;
    for (i=0;i < strlen(format);i++)
    {
        if (format[i] == '%')
        l++;
    }
    i = 0;
    va_start(ap, 1 - 1);
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
//////////////////////////////////////////////////////////////////
int _SINT_PR(const char *format,...)
{
    va_list ap;
    unsigned int l;
    int count = 1, i;
    char * arg;

    i = l = 0;
    for (i=0;i < strlen(format);i++)
    {
        if (format[i] == '%')
        l++;
    }
    i = 0;
    va_start(ap, 1 - 1);
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
//////////////////////////////////////////////////////////////////
int _OCTAL_PR(unsigned long arg)
{
    unsigned int l = 0;
    int count = 1, i = 0;
    unsigned long p = 0 ,q = 0, t, r;
    t = ULONG_MAX;

    q = arg;
    while(q != 0)
    {
        if (q == 1)
            r = 1;
        else
            r = (q % 8);
        t = t * 10;
        p = p + ((t / 10) * r);
        q = q / 8;
        printf("%lu\n%lu\n%d\n%lu\n", arg, p, r , (unsigned long)t);
    }
        printf("%d\n%d\n\n", p, t);
        p = t - 1 - p;
        t = t / 10;
    while(p != 0)
    {
        q = (p/t);
        p = p % t;
        t = t/10;
        if (q == 9)
            write(1,"0",1);
        else
            write(1,"1",1);
        count++;
    }
}
//////////////////////////////////////////////////////////////////
int _BYTE_PR(int arg)
{
            unsigned int count, q = 0 ,p = 0 , r, t = 1;
            q = arg;
            while(q != 0)
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
            while(p != 0)
            {
            q = (p/t);
            p = p % t;
            t = t/10;
            if (q == 9)
                write(1,"0",1);
            else
                write(1,"1",1);
            count++;
            }
}

//////////////////////////////////////////////////////////////////
int _UNSTRING_PR(char *arg)
{
    unsigned int l;
    int count = 1, i,j;
            int a = 0, c = 0, q = 0, r = 0;
            for(j=0;j < strlen(arg);j++)
            {
                c = (int)arg[j];
                if ((c > 0 && c < 32) || c >= 127)
                {
                    write(1,"\\",1);
                    write(1,"x",1);
                    if (c < 15)
                        write(1,"0",1);
                        _HEX_PR(c);
                }
                else
                    write(1,&arg[j],1);
                count++;
            }
}

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

int _CHAR_PR(char ar)
{
    write(1,&ar,sizeof(ar));
}

//////////////////////////////////////////////////////////////////
int _hex_PR(unsigned int arg)
{
            unsigned int j = 0, q = 0 ,count ,p = 0 , t = 1;
            int r, i = 0;
            char tmp;
            char *c;
            //ar = va_arg(ap, unsigned int);
            c = malloc((log10(arg) + 2)*sizeof(char));

            q = arg;
            while(q != 0)
            {
                if (q == 1)
                    r = 1;
                else
                    r = (q % 16);

                switch(r)
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
            for(; i >= 0 ; i--)
            {
                write(1,&c[i],1);
            }
        }
//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
int _UINT_PR(const char *format,...)
{
    va_list ap;
    unsigned int l;
    int count = 1, i;
    char * arg;

    i = l = 0;
    for (i=0;i < strlen(format);i++)
    {
        if (format[i] == '%')
        l++;
    }
    i = 0;
    va_start(ap, 1 - 1);

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

////////////////////////////////////////////////////////////////////
int _STRING_PR(char * arg)
{
    unsigned int l;
    int count = 1, i, j;
    for(j=0;j < strlen(arg);j++)
    {
        write(1,&arg[j],1);
        count++;
    }
}

////////////////////////////////////////////////////////////////////

int _HEX_PR(unsigned int arg)
{
    unsigned int ar , q = 0 ,p = 0 , t = 1;
    int r, i;
    char tmp;
    char *c;
    c = malloc((log10(arg) + 2)*sizeof(char));
    q = arg;
            while(q != 0)
            {
                if (q == 1)
                    r = 1;
                else
                    r = (q % 16);
                switch(r)
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
            for(; i >= 0 ; i--)
            {
                write(1,&c[i],1);
            }
            p = t - 1 - p;
            t = t / 10;
}

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

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
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    printf("%u\n", ui);
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    //_printf("Unsigned octal:[%o]\n", 83);
    //_printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    //_printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("%b\n", 98);
    printf("%b\n", 98);
    printf("%d\n", (int)'c');
    _printf("%S", "Best\nSchool");
    return (0);
}
