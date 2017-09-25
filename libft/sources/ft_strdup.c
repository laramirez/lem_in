/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:24:09 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/14 15:06:59 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!s1 || !(cpy = ft_strnew(sizeof(char) * ft_strlen(s1))))
		return (NULL);
	while (*s1)
	{
		cpy[i] = *s1;
		i++;
		s1++;
	}
	return (cpy);
}
