#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <stdarg.h>
#include <stdint.h>
#include <float.h>
int _HEX_PR(unsigned int ar, int count);
int _ADDRESS_PR(char *arg, int count);
int _SINT_PR(int arg, int count);
int _OCTAL_PR(unsigned long arg, int count);
int _BYTE_PR(int arg, int count);
int _UNSTRING_PR(char *arg, int count);
int _CHAR_PR(char ar, int count);
int _hex_PR(unsigned int arg, int count);
int _UINT_PR(unsigned int arg, int count);
int _STRING_PR(char * arg, int count);
int _HEX_PR(unsigned int arg, int count);
int _printf(const char *format, ...);
int _FSPECIFIER(char ctmp, void *arg);
unsigned int numdigits(unsigned int arg);
#endif
