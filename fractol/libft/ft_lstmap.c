/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:05:19 by abechet           #+#    #+#             */
/*   Updated: 2018/11/20 13:39:07 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new_lst;

	if (!lst || !f)
		return (NULL);
	first = f(lst);
	new_lst = first;
	if (first == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new_lst->next = f(lst);
		if (new_lst->next == NULL)
			return (NULL);
		new_lst = new_lst->next;
	}
	return (first);
}
