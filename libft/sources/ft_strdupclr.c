/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:24:09 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdupclr(char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = ft_strnew(sizeof(char) * ft_strlen(s1))))
		return (NULL);
	while (cpy[i])
	{
		cpy[i] = s1[i];
		s1[i] = '\0';
		i++;
	}
	return (cpy);
}
