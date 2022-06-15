#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int _printf(const char *format, ...);
char *ctoa(unsigned int num, int radix); /*convert to ascii*/
/*specifically for lower case hexadecimal*/
char *ctoa_lower(unsigned int num, int radix);
#endif
