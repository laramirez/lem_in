/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:27:28 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_filltab(char const *s, char **ret, size_t count, char c)
{
	size_t	i;
	char	*start;

	i = 0;
	while (count)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		if (*s && *s != c)
		{
			while (*s && *s != c)
				s++;
			if (!(ret[i] = ft_strsub(start, 0, (s - (const char *)start))))
				return (NULL);
			count--;
			i++;
		}
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**ret;

	if (s)
	{
		count = ft_countwords(s, c);
		if (!(ret = ft_strtabnew(count)))
			return (NULL);
		return (ft_filltab(s, ret, count, c));
	}
	return (NULL);
}
