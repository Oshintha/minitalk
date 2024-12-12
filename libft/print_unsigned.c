/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:39:58 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/14 18:22:47 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_size(unsigned int n)
{
	unsigned int	i;
	unsigned int	count;

	i = n;
	count = 0;
	while (i >= 10)
	{
		count++;
		i = i / 10;
	}
	return (count + 1);
}

int	print_unsigned(unsigned int n)
{
	char	res;
	int		size;

	size = check_size(n);
	if (n >= 10)
	{
		res = n % 10 + '0';
		if (print_unsigned(n / 10) == -1)
			return (-1);
	}
	else
		res = n + '0';
	if (print_char(res) == -1)
		return (-1);
	return (size);
}
