/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_ft_popen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:10:40 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/06 21:12:08 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    int fd[2];
    pit_t pid;

    
}