/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:40:56 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 14:56:39 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(int n)
{
	int	i;
	int	temp;

	if (n == 0)
		return (1);
	temp = n;
	i = 0;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

static int	check_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;
	int		temp;

	i = count_number(n);
	sign = check_sign(n);
	str = (char *)malloc(sizeof(char) * (i + 1 + (sign == -1)));
	if (!str)
		return (NULL);
	str[i + (sign == -1)] = '\0';
	temp = n;
	while (i-- > 0)
	{
		str[i + (sign == -1)] = '0' + (temp % 10) * sign;
		temp /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
