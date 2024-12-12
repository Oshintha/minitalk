/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:34 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/14 19:00:04 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len(unsigned int value)
{
	int	len;

	len = 0;
	while (value != 0)
	{
		value = value / 16;
		len++;
	}
	return (len);
}

static int	puthex(unsigned int value, char type)
{
	if (value >= 16)
	{
		if (print_hex(value / 16, type) == -1)
			return (-1);
		print_hex(value % 16, type);
	}
	else
	{
		if (value <= 9)
			return (print_char(value + '0'));
		else
		{
			if (type == 'x')
				return (print_char(value - 10 + 'a'));
			if (type == 'X')
				return (print_char(value - 10 + 'A'));
			else
				return (-1);
		}
	}
	return (0);
}

int	print_hex(unsigned int value, char type)
{
	if (value == 0)
		return (print_char('0'));
	if (puthex(value, type) == -1)
		return (-1);
	return (check_len(value));
}
