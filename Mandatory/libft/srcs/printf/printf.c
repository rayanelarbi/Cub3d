/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:22:12 by boschwie          #+#    #+#             */
/*   Updated: 2024/12/20 10:39:03 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	printf_arg(va_list args, const char format)
{
	if (format == 'c')
		return (put_char(va_arg(args, int)));
	else if (format == 's')
		return (put_str(va_arg(args, char *)));
	else if (format == 'p')
		return (put_pointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (put_numb(va_arg(args, int)));
	else if (format == 'u')
		return (put_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (put_hexadecimal(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (put_char('%'));
	return (0);
}

int	print_f(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			printed;

	if (!format)
		return (-1);
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed += printf_arg(args, format[i + 1]);
			i++;
		}
		else
			printed += put_char(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	my_count;
// 	int	original_count;

// 	printf("------------------%%c------------------");
// 	my_count = printf("Hello, %c!\n", 'a');
// 	original_count = printf("Hello, %c!\n", 'a');

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%s------------------");
// 	my_count = printf("Hello, %s!\n", "Everyone");
// 	original_count = printf("Hello, %s!\n", "Everyone");

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%p------------------");
// 	my_count = printf("Hello, %p!\n", &"Hey");
// 	original_count = printf("Hello, %p!\n", &"Hey");

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%d------------------");
// 	my_count = printf("Hello, %d!\n", 22234);
// 	original_count = printf("Hello, %d!\n", 22234);

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%i------------------");
// 	my_count = printf("Hello, %i!\n", 22234);
// 	original_count = printf("Hello, %i!\n", 22234);

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%u------------------");
// 	my_count = printf("Hello, %u!\n", 22234);
// 	original_count = printf("Hello, %u!\n", 22234);

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%x------------------");
// 	my_count = printf("Hello, %x!\n", 22234);
// 	original_count = printf("Hello, %x!\n", 22234);

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%X------------------");
// 	my_count = printf("Hello, %X!\n", 22234);
// 	original_count = printf("Hello, %X!\n", 22234);

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);

// 	printf("------------------%%%%------------------");
// 	my_count = printf("Hello, %%!\n");
// 	original_count = printf("Hello, %%!\n");

// 	printf("My : %d\n", my_count);
// 	printf("Their : %d\n", original_count);
// 	return (0);
// }
