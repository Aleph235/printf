#include "main.h"
#include <stdarg.h>
/**
 * get_op_func - function that selects the correct operation
 * @s: char operation
 *
 * Return: pointer to the correct func
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	pr_t p[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int}
	};

	for (i = 0; p[i].type != NULL; i++)
	{
		if (*(p[i].type) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}
/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		
		for (; format[i] != '%' && format[i]; i++)
		{
		
			_putchar(format[i]);
			count++;
		}
			if (format[i] == '%' && format[i + 1] == '%')
		{	_putchar('%' + 0);
			return (1);
		}
		if (!format[i])
			return (count);
		f = check_for_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}