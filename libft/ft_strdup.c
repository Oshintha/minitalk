/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:49:26 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 14:55:03 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * dstsize);
	if (!(new))
		return (NULL);
	ft_strlcpy(new, s1, dstsize);
	return (new);
}
