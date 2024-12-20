/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:39:10 by aoshinth          #+#    #+#             */
/*   Updated: 2024/12/20 14:55:02 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <signal.h>

volatile sig_atomic_t	g_ack_received = 0;

void	ft_error_client(const char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	send_signal(int pid, unsigned char character)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((character >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error_client("Error PID: Failed to send SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error_client("Error PID: Failed to send SIGUSR2");
		}
		g_ack_received = 0;
		usleep(500);
		if (g_ack_received == -1)
		{
			ft_error_client("Error: Server reported an issue with the signal.");
			g_ack_received = 0;
		}
	}
}

int	validate_pid(const char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
			ft_error_client("Error: Invalid PID format. Use numeric PID.");
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
		ft_error_client("Error: PID must be a positive integer.");
	return (pid);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ack_received = 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	char				*message;
	int					i;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		ft_error_client("Error: Incorrect number of arguments.");
	}
	pid = validate_pid(av[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_client("Error: Failed to set up signal handlers.");
	message = av[2];
	i = 0;
	while (message[i])
		send_signal(pid, message[i++]);
	send_signal(pid, '\0');
	ft_printf("Message sent successfully to PID %d\n", pid);
	return (0);
}
