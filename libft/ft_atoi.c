/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:42:56 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 14:57:02 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	result;
	long long int	check;
	int				sign;

	result = 0 ;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		check = result;
		result = result * 10 + *str - '0';
		if (result / 10 != check && sign < 0)
			return (0);
		if (result / 10 != check && sign > 0)
			return (-1);
		str++;
	}
	return (result * sign);
}
