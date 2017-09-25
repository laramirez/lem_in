/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:14:08 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/15 15:19:49 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = (t_list *)ft_memalloc(sizeof(t_list));
	new = f(lst);
	ret = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = (t_list *)ft_memalloc(sizeof(t_list));
		new->next = f(lst);
		new = new->next;
	}
	return (ret);
}
