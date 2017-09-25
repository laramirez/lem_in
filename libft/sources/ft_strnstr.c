/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:11:05 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == *little && ft_strnequ(&big[i], little, ft_strlen(little)))
		{
			if ((i + ft_strlen(little)) <= len)
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
