/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:40:31 by aoshinth          #+#    #+#             */
/*   Updated: 2024/12/20 13:38:14 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <signal.h>

volatile sig_atomic_t	g_current_client_pid = 0;

void	process_bit(int signal, unsigned char *current_char, int *bit_index)
{
	if (signal == SIGUSR1)
		*current_char |= (1 << (7 - *bit_index));
	(*bit_index)++;
}

void	process_character(unsigned char *current_char, int *bit_index)
{
	if (*current_char == '\0')
	{
		ft_printf("\n");
		*bit_index = 0;
		*current_char = 0;
		g_current_client_pid = 0;
	}
	else
	{
		ft_printf("%c", *current_char);
		*bit_index = 0;
		*current_char = 0;
	}
}

void	ft_error_server(const char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

	(void)context;
	if (g_current_client_pid == 0)
	{
		g_current_client_pid = info->si_pid;
	}
	else if (info->si_pid != g_current_client_pid)
	{
		return ;
	}
	process_bit(signal, &current_char, &bit_index);
	if (bit_index == 8)
	{
		process_character(&current_char, &bit_index);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_error_server("Error: Failed to send acknowledgment signal.");
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	(void)av;
	if (ac != 1)
		ft_error_server("Error: wrong format\nTry again with: ./server");
	ft_printf("Server PID: %d\nWaiting for messages...\n", getpid());
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		||sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error_server("Error: Sigaction failed");
	while (1)
		pause();
	return (0);
}
