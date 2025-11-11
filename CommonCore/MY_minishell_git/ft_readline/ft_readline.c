/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:45:00 by twtan             #+#    #+#             */
/*   Updated: 2025/10/30 15:45:02 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_readline.h"

char	*ft_readline(char *cmd_prompt)
{
	char	*cmd;
	int		count;

	ft_printf("%s ", cmd_prompt);
	cmd = get_next_line(2);
	count = 0;
	while (cmd[count + 1] != 0)
		count++;
	cmd[count] = 0;
	return (cmd);
}
