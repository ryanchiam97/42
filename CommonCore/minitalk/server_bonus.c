/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:14:50 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/18 18:02:29 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	clearbitcountandc(int *bitcount, unsigned char *c)
{
	*bitcount = 0;
	*c = 0;
}

void	endofmessage(pid_t s, int *client_pid, int *bitcount, unsigned char *c)
{
	kill(s, SIGUSR1);
	kill(s, SIGUSR2);
	ft_printf("\nmessage from client %i complete!\n", *client_pid);
	*client_pid = 0;
	clearbitcountandc(bitcount, c);
}

void	handlebits(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bitcount = 0;
	static int				client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		clearbitcountandc(&bitcount, &c);
		client_pid = info->si_pid;
	}
	if (client_pid == 0)
		client_pid = info->si_pid;
	c = (c << 1) | (sig == SIGUSR2);
	bitcount++;
	if (bitcount == 8)
	{
		if (c == '\0')
			endofmessage(info->si_pid, &client_pid, &bitcount, &c);
		else
			write(1, &c, 1);
		clearbitcountandc(&bitcount, &c);
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
