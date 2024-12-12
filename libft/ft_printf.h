/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:27:23 by aoshinth          #+#    #+#             */
/*   Updated: 2024/07/26 12:05:40 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		print_char(char c);
int		print_string(char *s);
int		print_pointer(size_t ptr);
int		print_int(int n);
int		print_unsigned(unsigned int nb);
int		print_hex(unsigned int value, char type);

#endif
