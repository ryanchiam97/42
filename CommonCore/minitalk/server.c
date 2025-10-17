/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:14:50 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/17 16:37:46 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handlebits(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bitcount = 0;
	static int				client_pid = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	c = (c << 1) | (sig == SIGUSR2);
	bitcount++;
	if (bitcount == 8)
	{
		if (c == '\0')
		{
			ft_printf("\nmessage from client%i complete!\n", client_pid);
			kill(info->si_pid, SIGUSR1);
			kill(info->si_pid, SIGUSR2);
			client_pid = 0;
		}
		else
			ft_printf("%c", c);
		c = 0;
		bitcount = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				current_pid;
	struct sigaction	sa;

	sa.sa_sigaction = handlebits;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	current_pid = getpid();
	ft_printf("%d\n", current_pid);
	while (1)
		pause();
}
