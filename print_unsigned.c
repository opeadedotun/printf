#include "main.h"

/**
 * print_unsigned - Function to print an unsigned number
 * @types: Variable to display the list of arguments
 * @buffer: Buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = (numb % 10) + '0';
		numb /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, percision, size));
}

/**
 * print_octal - FUnction to print an unsigned number in octal notation
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Function to print an unsigned
 * number in hexadecimal notation
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags,
				'x', width, precision, size));
}

/**
 * print_hexa_upper - Function to print an unsigned
 * number in upper hexadecimal notation
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
'X', width, precision, size));
}

/**
 * print_hexa - Function to print an unsigned number in
 * lower or upper hexadecimal notation
 * @types: Variable for displaying the list of arguments
 * @map_to: Variable to hold the array of values to map number
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @flag_ch: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(num, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
