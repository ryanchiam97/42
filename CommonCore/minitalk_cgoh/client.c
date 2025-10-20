/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:14:42 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/20 21:03:54 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	sendchar(pid_t server_pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		if (g_ack == 0)
			pause();
	}
	while (g_ack == 0)
		pause();
}

void	signalhandler(int sig)
{
	if (sig == SIGUSR1 && g_ack != 2)
		g_ack = 1;
	else if (sig == SIGUSR2)
		g_ack = 2;
}

int	setup(void)
{
	struct sigaction	sa;

	sa.sa_handler = signalhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	char		*message;
	int			i;

	if (setup() != 1 || argc != 3 || ft_strlen(argv[2]) == 0)
		return (write(1, "\nExpected:./client {toPID}{nonemptymessage}\n", 43));
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (1)
	{
		sendchar(server_pid, (unsigned char)message[i]);
		if (message[i] == '\0')
			break ;
		i++;
	}
	while (g_ack != 2)
		pause();
	ft_printf("\nRecieved SIGUSR2 ack signal from server... Exiting\n");
	exit (0);
}
