/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:37:56 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/22 15:59:45 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*first_el;

	if (!lst || !f || !del)
		return (NULL);
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	first_el = res;
	while (lst)
	{
		res->content = f(lst->content);
		lst = lst->next;
		if (!lst)
			break ;
		res->next = malloc(sizeof(t_list));
		if (!res->next)
		{
			ft_lstclear(&first_el, del);
			return (NULL);
		}
		res = res->next;
	}
	res->next = NULL;
	return (first_el);
}
