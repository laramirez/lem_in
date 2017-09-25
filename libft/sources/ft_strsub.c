/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:39:39 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/14 21:37:35 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*extract;

	if (s)
	{
		extract = ft_strnew(len);
		i = 0;
		while (len)
		{
			extract[i] = s[start];
			i++;
			start++;
			len--;
		}
		return (extract);
	}
	return (NULL);
}
