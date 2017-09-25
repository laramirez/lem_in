/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 23:49:28 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/15 15:19:49 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_list;
	t_list	*tmp_next;

	tmp_list = *alst;
	while (tmp_list)
	{
		tmp_next = tmp_list->next;
		del(tmp_list->content, tmp_list->content_size);
		free(tmp_list);
		tmp_list = tmp_next;
	}
	*alst = NULL;
}
