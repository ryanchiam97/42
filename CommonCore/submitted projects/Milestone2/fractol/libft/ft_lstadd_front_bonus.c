/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:30:04 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/10 19:47:21 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
// int	main(void)
// {
// 	char s1[] = "one";
// 	char s2[] = "two";
// 	t_list *n1 = ft_lstnew(s1);
// 	t_list *n2 = ft_lstnew(s2);
// 	ft_lstadd_front(&n1, n2);
// 	printf("%s", (char *)n1->content);
// }