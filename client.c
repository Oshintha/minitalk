/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:39:10 by aoshinth          #+#    #+#             */
/*   Updated: 2024/11/29 23:39:10 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

void	send_signal(int pid, unsigned char character)
{
	int				i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((character >> i) % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}
int	main(int ac, char **av[])
{
	int			i;

	i=0;
	if (argc != 3)
	{
		ft_printf("Error: Try again with correct format"); //if needed,  exit(ft_printf("Error: Try again with correct format"))
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	while (av[1][i])
	{
		if(av[1][i] < '0' || av[i][i] > '9')
			exit(ft_printf("Error: Try again with correct PID"));
		i++;
	}
	message = argv[2];
	i = 0;
	while (message[i])
	send_signal(ft_atoi(av[1]), message[i++]);
	send_signal(ft_atoi(av[1]), '\0');
    send_signal(ft_atoi(av[1]), '\n');
    return (0);
}
