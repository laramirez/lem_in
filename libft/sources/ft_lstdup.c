/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:09:32 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/07 18:09:57 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstdup(t_list *path)
{
	t_list	*scan;
	t_list	*path_cpy;

	scan = path;
	path_cpy = (t_list *)ft_memalloc(sizeof(t_list));
	while (scan)
	{
		ft_lstaddend(&path_cpy, ft_lstnew(scan->data, scan->data_size));
		scan = scan->next;
	}
	return(path_cpy);
}