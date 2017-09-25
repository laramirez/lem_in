/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:53:28 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/17 13:12:53 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		new = ft_strnew(ft_strlen(s2));
		ft_strcpy(new, s2);
		ft_strdel(&s2);
	}
	else if (!s2)
	{
		new = ft_strnew(ft_strlen(s1));
		ft_strcpy(new, s1);
		ft_strdel(&s1);
	}
	else
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		ft_strcpy(new, s1);
		ft_strcpy(&new[ft_strlen(s1)], s2);
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}
