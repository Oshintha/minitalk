/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:34:21 by aoshinth          #+#    #+#             */
/*   Updated: 2024/09/27 13:58:09 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	total_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	total_len = dst_len + ft_strlen(src);
	if (dst_len >= dstsize)
		return (total_len);
	i = 0;
	while (src[i] && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (total_len);
}
