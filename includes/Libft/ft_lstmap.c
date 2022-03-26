/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:25:22 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:17:34 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*first;

	if (lst == 0 || f == 0)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (new == 0)
		return (0);
	first = new;
	while (lst->next != 0)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		new = new->next;
		if (new == 0)
		{
			ft_lstclear(&first, del);
			return (0);
		}
	}
	return (first);
}
