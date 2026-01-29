/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:53:12 by rchiam            #+#    #+#             */
/*   Updated: 2026/01/28 11:55:59 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define RTN_ERR 1
#define RTN_OK 0

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == 0)
		return (perror("Error:"), RTN_ERR);

	//
}