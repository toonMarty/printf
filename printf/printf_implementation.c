#include "main.h"
/**
 * ctoa - function that converts a number to ASCII based on the
 * radix
 *  @num: the number to convert
 * @radix: the base,can be 10, 16, 8 or 2
 * Return: the converted number
 */
char *ctoa(unsigned int num, int radix)
{
	static const char num_rep[] = "0123456789ABCDEFabcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = num_rep[num % radix];
		num /= radix;
	} while (num != 0);

	return (ptr);
}


/**
 * ctoa_lower - converts a number
 * to hex_values (lowercase)
 * @num: the number to be converted
 * @radix: the base to convert to
 * Return: the converted number
 */
char *ctoa_lower(unsigned int num, int radix)
{
	static const char num_rep[] = "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = num_rep[num % radix];
		num /= radix;
	} while (num != 0);

	return (ptr);
}

/**
 * _printf - function that prints character(s) on the
 * stdout
 * @format: a string of chars which
 * can be a set of specifiers or simple word strings
 * @...: a variable number of arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	/*Accessing the arguments - Printing a single character*/

	unsigned long int i;
	unsigned long int j;
	char percent_sign = '%';
	char character = 'c';
	char str = 's';
	char decimal = 'd';
	char ics = 'i'; /*integer conversion specifier*/
	char binary_specifier = 'b';
	char u_decimal_specifier = 'u';
	char octal_specifier = 'o';
	char hex_specifier = 'x';
	char upper_hex_specifier = 'X';
	char cus_str_specifier = 'S';
	char mem_specifier = 'p';
	char *buffer;

	/*char *buffer;*/
	va_list va;

	va_start(va, format);

	buffer = malloc(1024);

	for (i = 0; i < strlen(format); i++)
	{
		/*printing characters*/
		if (format[i] == percent_sign && format[i + 1] == character)
		{
			int char_value = va_arg(va, int);

			write(1, &char_value, sizeof(char));
		}
		/*handle strings with string specifier*/
		if (format[i] == percent_sign && format[i + 1] == str)
		{
			char *str_value = va_arg(va, char *);

			for (j = 0; j < strlen(str_value); j++)
			{
				if (str_value[j] != '\0')
				{
					write(1, &str_value[j], (sizeof(char) * sizeof(*(str_value + j))));
				}
				else
				{
					break;
				}
			}
			if (format[i] == percent_sign
			&& (format[i + 1] == decimal || format[i + 1] == ics))
			{
				int i = va_arg(va, int);

				if (i < 0)
				{
					i = -i;
					putchar('-');
				}

				puts(ctoa(i, 10));
			}
			if (format[i] == percent_sign && format[i + 1] == binary_specifier)
			{
				int bin_value = va_arg(va, unsigned int);

				puts(ctoa(bin_value, 2));
			}
			if (format[i] == percent_sign && format[i + 1] == u_decimal_specifier)
			{
				unsigned int u_decimal_value = va_arg(va, unsigned int);

				puts(ctoa(u_decimal_value, 10));
			}
			if (format[i] == percent_sign && format[i + 1] == octal_specifier)
			{
				unsigned int octal_value = va_arg(va, unsigned int);

				puts(ctoa(octal_value, 8));
			}
			if (format[i] == percent_sign && format[i + 1] == upper_hex_specifier)
			{
				unsigned int hex_value = va_arg(va, unsigned int);

				puts(ctoa(hex_value, 16));
			}
			if (format[i] == percent_sign && format[i + 1] == hex_specifier)
			{
				unsigned int l_hex_value = va_arg(va, unsigned int);

				puts(ctoa_lower(l_hex_value, 16));
			}
			if ((format[i] == percent_sign && format[i + 1] == cus_str_specifier)
			|| ((format[i + 2] == '\\') && (format[i + 3] == 'n')))
			{
				char *cus_str_value = va_arg(va, char *);

				for (j = 0; j < strlen(cus_str_value); j++)
				{
					buffer[j] += cus_str_value[j];
					if (cus_str_value[j] == '\n')
					{
						buffer[j] += printf("\\x%02X", putchar(cus_str_value[j]));
					}
					else if (cus_str_value[j] == '\b')
					{
						buffer[j] += printf("\\x%02X", putchar(cus_str_value[j]));
					}
					else if (cus_str_value[j] == '\a')
					{
						buffer[j] += printf("\\x%02X", putchar(cus_str_value[j]));
					}
					else if (cus_str_value[j] == '\t')
					{
						buffer[j] += printf("\\x%02X", putchar(cus_str_value[j]));
					}
					if (buffer[j] != '\0')
					{
						putchar(buffer[j]);
					}
					else
					{
						break;
					}
				}
			}
			if (format[i] == percent_sign && format[i + 1] == mem_specifier)
			{
				unsigned int mem_value = va_arg(va, unsigned int);

				puts(ctoa(mem_value, 16));
			}
		}
		va_end(va);
		return (write(1, &format, 1));
}
