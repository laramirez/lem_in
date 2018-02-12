/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:29:40 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/12 19:45:01 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *data, size_t data_size)
{
	t_list	*newlist;

	ft_printf("data (%x) created\n", data);
	newlist = (t_list *)ft_memalloc(sizeof(t_list));
	if (!data)
	{
		newlist->data = NULL;
		newlist->data_size = 0;
	}
	else
	{
		newlist->data = ft_memalloc(data_size);
		ft_memcpy(newlist->data, data, data_size);
		newlist->data_size = data_size;
	}
	newlist->next = NULL;
	return (newlist);
}
