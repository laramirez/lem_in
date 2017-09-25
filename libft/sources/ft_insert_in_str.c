/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:01:37 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_insert_in_str(char *s1, char *s2, size_t pos)
{
	char	*new;
	size_t	i;

	if (!s2)
		return (NULL);
	if (!s1 || pos >= ft_strlen(s2))
		return (s2);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	while (i < pos)
	{
		new[i] = s2[i];
		i++;
	}
	ft_strcpy(&new[i], s1);
	i += ft_strlen(s1);
	ft_strcpy(&new[i], &s2[pos]);
	free(s2);
	return (new);
}
