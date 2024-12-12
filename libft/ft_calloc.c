/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:29:34 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 14:56:53 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*value;

	if (count > 0 && size > 0 && count > UINT_MAX / size)
		return (NULL);
	total_size = count * size;
	value = malloc(total_size);
	if (!value)
		return (NULL);
	ft_memset(value, 0, total_size);
	return (value);
}
