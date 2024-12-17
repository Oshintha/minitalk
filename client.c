/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:39:10 by aoshinth          #+#    #+#             */
/*   Updated: 2024/12/13 13:57:43 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signal(int pid, unsigned char character)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		// Check the current bit and send the corresponding signal
		if ((character >> i) % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100); // Slightly larger delay for reliability
	}
}

int	validate_pid(const char *pid_str)
{
	int	i;

	i = 0;
	while (pid_str[i])
	{
		// Ensure all characters in PID string are digits
		if (pid_str[i] < '0' || pid_str[i] > '9')
		{
			ft_printf("Error: Invalid PID format. Please use numeric PID.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (ft_atoi(pid_str));
}

void	print_usage_and_exit(const char *program_name)
{
	ft_printf("Usage: %s <PID> <MESSAGE>\n", program_name);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		ft_printf("Error: Incorrect number of arguments.\n");
		print_usage_and_exit(av[0]);
	}

	// Validate and parse PID
	pid = validate_pid(av[1]);

	// Get the message from arguments
	message = av[2];
	i = 0;
	while (message[i])
		send_signal(pid, message[i++]);

	// Send a null byte and newline to indicate end of message
	send_signal(pid, '\0');
	send_signal(pid, '\n');
	return (0);
}
