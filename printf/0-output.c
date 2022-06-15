#include "main.h"
int _printf(const char *format, ...)
{
	char percent_sign = '%';
	char character = 'c';
	char str = 's';

	va_list va;

	va_start(va, format);

	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] == percent_sign && format[i + 1] == character)
		{
			int char_value = va_arg(va, int);

			write(1, &char_value, sizeof(char));
		}
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
		}
	}
	va_end(va);
	return (write(1, &format, 1));
}
