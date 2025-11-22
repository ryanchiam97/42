/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokeniser.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twtan <twtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:38:52 by twtan             #+#    #+#             */
/*   Updated: 2025/11/20 16:38:55 by twtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKENISER_H
# define MINISHELL_TOKENISER_H

# include "../ft_split_r/ft_split_r.h"

typedef struct s_node
{
	char	*name; 		// readable aid for user in identifying layer
	int	type;		// reserved usage, maybe to indicate actionable function to attach
	void	**nodes;	// tree branches
	int	layer;		// placeholder to indicate which layer 
}	t_node;


#endif
