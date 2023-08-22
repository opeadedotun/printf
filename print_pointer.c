#include "main.h"

/**
 * print_pointer - Function to print the value of a pointer variable
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length, width, flags,
	padd, extra_c, padd_start));
}

/**
 * print_non_printable - Function to print
 * the ASCII codes in non-printable chars
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int x = 0, off_set = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (is_printable(str[x]))
			buffer[x + off_set] = str[x];
		else
			off_set += append_hexa_code(str[x], buffer, x + off_set);

		x++;
	}

	buffer[x + off_set] = '\0';

	return (write(1, buffer, x + offset));
}

/**
 * print_reverse - Function to print reverse string
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char *str;
	int x, counter = 0;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);
		counter++
	}
	return (counter);
}

/**
 * print_rot13string - Function to print a string in rot13
 * @types: Variable for displaying the list of arguments
 * @buffer: Variable to display buffer array
 * @flags: Variable to calculate active flags
 * @width: Variable to hold the value of width
 * @precision: Variable to hold the precision specification
 * @size: Variable to hold the size specifier
 * Return: Return the number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char z;
	char *str;
	unsigned int x, y;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (x = 0; str[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == str[x])
			{
				z = out[y];
				write(1, &z, 1);
				counter++;
				break;
			}
		}
		if (!in[y])
		{
			z = str[x];
			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
