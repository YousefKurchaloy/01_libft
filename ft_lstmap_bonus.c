/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:42 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/10 16:08:48 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	current = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		new = ft_lstnew(mapped_content);
		if (!new || !mapped_content)
		{
			free(mapped_content);
			ft_lstdelone(new, del);
			ft_lstclear(&current, del);
			return (NULL);
		}
		ft_lstadd_back(&current, new);
		lst = lst->next;
	}
	return (current);
}
