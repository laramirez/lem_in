/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:54:28 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/17 13:15:01 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnjoinfree(char *s1, char *s2, size_t len_1, size_t len_2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		new = ft_strnew(len_2);
		ft_memcpy(new, s2, len_2);
		ft_strdel(&s2);
	}
	else if (!s2)
	{
		new = ft_strnew(len_1);
		ft_memcpy(new, s1, len_1);
		ft_strdel(&s1);
	}
	else
	{
		new = ft_strnew(len_1 + len_2);
		ft_memcpy(new, s1, len_1);
		ft_memcpy(&new[len_1], s2, len_2);
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}
