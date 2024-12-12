/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:25:18 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 11:31:32 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char input, va_list arg)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += print_char(va_arg(arg, int));
	else if (input == 's')
		i += print_string(va_arg(arg, char *));
	else if (input == 'p')
		i += print_pointer(va_arg(arg, size_t));
	else if (input == 'd')
		i += print_int(va_arg(arg, int));
	else if (input == 'i')
		i += print_int(va_arg(arg, int));
	else if (input == 'u')
		i += print_unsigned(va_arg(arg, unsigned int));
	else if (input == 'x')
		i += print_hex(va_arg(arg, unsigned int), input);
	else if (input == 'X')
		i += print_hex(va_arg(arg, unsigned int), input);
	else if (input == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	int				check;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			check = check_type(*input++, args);
			if (check == -1)
				return (-1);
			i += check;
		}
		else
		{
			if (print_char(*input++) == -1)
				return (-1);
			i++;
		}
	}
	va_end(args);
	return (i);
}
