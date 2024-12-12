/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:02:49 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/15 09:16:45 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int n, int fd)
{
	char	result;

	if (n == -2147483648)
	{
		if (write (fd, "-2147483648", 11) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (write (fd, "-", 1) == -1)
				return (-1);
			n = -n;
		}
		if (n >= 10)
		{
			if (ft_putnbr(n / 10, fd) == -1)
				return (-1);
		}
		result = (n % 10) + '0';
		if (write (fd, &result, 1) == -1)
			return (-1);
	}
	return (0);
}

int	print_int(int n)
{
	int				nb;
	unsigned int	i;

	nb = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	if (ft_putnbr(n, 1) == -1)
		return (-1);
	if (n == -2147483648)
		return (11);
	return (i);
}
