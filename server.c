/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:40:31 by aoshinth          #+#    #+#             */
/*   Updated: 2024/12/13 15:26:16 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define END_TRANSMISSION '\0'

/**
 * @brief Handles received signals (SIGUSR1 or SIGUSR2) to reconstruct characters bit by bit.
 *
 * @param signal SIGUSR1 (bit = 1) or SIGUSR2 (bit = 0)
 */
void	handle_signal(int signal)
{
	static unsigned char	current_char = 0;
	static int				bit_index = 0;

	// Add the current bit to current_char
	current_char |= (signal == SIGUSR1);
	bit_index++;

	// If 8 bits have been received, process the character
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			ft_printf("\n"); // Print a newline if the transmission ends
		else
			ft_printf("%c", current_char); // Print the reconstructed character
		fflush(stdout); // Ensure output is printed immediately
		// Reset for the next character
		bit_index = 0;
		current_char = 0;
	}
	else
	{
		// Shift left to prepare for the next bit
		current_char <<= 1;
	}
}

/**
 * @brief Main function: prints PID and sets up signal handling.
 *
 * @return int Always 0.
 */
int	main(void)
{
	// Print the server PID so the client can use it
	printf("Server PID: %d\n", getpid());

	// Set up signal handlers
	if (signal(SIGUSR1, handle_signal) == SIG_ERR ||
		signal(SIGUSR2, handle_signal) == SIG_ERR)
	{
		perror("Signal error");
		exit(EXIT_FAILURE);
	}

	// Enter an infinite loop to wait for signals
	while (1)
		pause();

	return (0);
}
