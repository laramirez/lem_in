/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:33:07 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/02 16:36:11 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t  len;

    len = 0;
    while (lst)
	{
		len++;
        lst = lst->next;
	}
    return (len);
}
