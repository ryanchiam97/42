/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:14:50 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/16 23:23:37 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <bits/types/__sigset_t.h>

int	main(void)
{
	__pid_t	__current_pid;

	__current_pid = getpid();
	ft_printf("%d\n", __current_pid);
}

// to do:
/*
1. server: print PID
2. client: take in PID and message
3. client: kill() to send signals bit by bit according to message
4. server to send ack to client(s) each bit (client unblock upon recieving), print at end msg and send end
5. client cleanup and end
*/

int				kill(__pid_t pid, int sig);

__sighandler_t	signal(int signum, __sighandler_t handler);

int				sigemptyset(__sigset_t *set);

int				sigaddset(__sigset_t *set, int sigsum);

int				sigaction(int signum, const struct sigaction *act,
					struct sigaction *oldact);

int				getpid(void);

int				pause(void);

unsigned int	sleep(unsigned int seconds);

int				usleep(useconds_t, usec);

void			exit(int status);


