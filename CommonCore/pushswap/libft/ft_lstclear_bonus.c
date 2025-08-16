/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:32:09 by rchiam            #+#    #+#             */
/*   Updated: 2025/05/27 22:18:47 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	del(lst->content);
// 	free(lst);
// }
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*output;

// 	output = malloc(sizeof(t_list) * 1);
// 	if (output == NULL)
// 		return (NULL);
// 	output->content = content;
// 	output->next = NULL;
// 	return (output);
// }
// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }
// unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (i < size - 1 && src[i] != '\0')
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	while (src[i])
// 		i++;
// 	return ((unsigned int)i);
// }
// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
// char	*ft_strdup(char *src)
// {
// 	char	*dest;
// 	int		len;

// 	len = ft_strlen(src) + 1;
// 	dest = (char *)malloc(sizeof(char) * len);
// 	if (dest == NULL)
// 		return (NULL);
// 	ft_strlcpy(dest, src, len);
// 	return (dest);
// }
// void	ft_del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	*s4;
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*l3;
// 	t_list	*l4;
// 	t_list	*temp;
// 	char	*s;

// 	s1 = ft_strdup("lorem");
// 	s2 = ft_strdup("ipsum");
// 	s3 = ft_strdup("dolor");
// 	s4 = ft_strdup("sit");
// 	l1 = ft_lstnew(s1);
// 	l2 = ft_lstnew(s2);
// 	l3 = ft_lstnew(s3);
// 	l4 = ft_lstnew(s4);
// 	l1->next = l2;
// 	l2->next = l3;
// 	l3->next = l4;
// 	l4->next = 0;
// 	ft_lstclear(&l1, &ft_del);
// }
