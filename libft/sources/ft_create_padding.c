/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:25:59 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/11 12:51:54 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_create_padding(char c, int size)
{
	char	*padding;
	int		i;

	if (size < 0)
		return (NULL);
	padding = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		padding[i] = c;
		i++;
	}
	return (padding);
}
