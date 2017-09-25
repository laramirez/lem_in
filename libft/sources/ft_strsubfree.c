/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 14:42:09 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:38:06 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
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
		free(s);
		return (extract);
	}
	return (NULL);
}
