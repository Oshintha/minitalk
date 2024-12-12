/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:38:59 by aoshinth          #+#    #+#             */
/*   Updated: 2024/09/27 13:44:44 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	size_t	i;

	if (!src && (!dst))
		return (dst);
	i = 0;
	dest1 = (char *)dst;
	src1 = (char *)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dst);
}
