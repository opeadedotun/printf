ude "main.h"
/**
 * handle_print - prints an argument based on its type
 * @fmt: Format string in which to print the argument.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @width: get width.
 * @precision: precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int hanle_print(const char *fmt, int *ind, va_list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, print_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, ('\0', NULL}
				};
				for (i = 0; fmt_types
