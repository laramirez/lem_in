/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:11:29 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/14 15:06:53 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!(ptr = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = (unsigned char)0;
		i++;
	}
	return (ptr);
}
