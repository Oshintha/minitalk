/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:07:07 by aoshinth          #+#    #+#             */
/*   Updated: 2024/09/27 13:44:23 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	if (!dst && !src)
		return (0);
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst <= src)
	{
		while (len--)
			*dst1++ = *src1++;
	}
	else
	{
		dst1 += len - 1;
		src1 += len - 1;
		while (len--)
			*dst1-- = *src1--;
	}
	return (dst);
}
