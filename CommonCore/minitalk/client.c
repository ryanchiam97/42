/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:14:42 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/17 16:37:28 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_ack = 0;

void	sendchar(pid_t server_pid, unsigned char c)
{
	int					i;

	i = 8;
	while (i--)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_ack != 1)
			pause();
	}
}

void	signalhandler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		g_ack = 2;
		ft_printf("\nclient recieved SIGUSR2 ack signal\n");
	}
}

void	setup(void)
{
	struct sigaction	sa;

	sa.sa_handler = signalhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (write(1, "\nExpected input: ./client {PID} {message}\n", 41));
	setup();
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
	usleep(5000);
	while (1)
	{
		if (g_ack != 2)
			break ;
		pause();
	}
	write(1, "\nexiting\n", 8);
	exit (0);
}
