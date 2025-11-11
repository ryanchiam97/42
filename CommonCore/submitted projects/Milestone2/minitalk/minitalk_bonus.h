/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:15:50 by rchiam            #+#    #+#             */
/*   Updated: 2025/10/20 19:47:39 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
//client
int		setup(void);
void	signalhandler(int sig);
void	sendchar(pid_t server_pid, unsigned char c);
//server
void	handlebits(int sig, siginfo_t *info, void *context);
void	endofmessage(pid_t s, int *client_pid, int *bitcount, unsigned char *c);
void	clearbitcountandc(int *bitcount, unsigned char *c);

#endif