/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:14:47 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:36:59 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_tabcpy(const int *tab, size_t size)
{
	int		*tab_cpy;
	size_t	i;

	i = 0;
	tab_cpy = (int *)ft_memalloc(sizeof(int) * (size + 1));
	while (size)
	{
		tab_cpy[i] = tab[i];
		i++;
		size--;
	}
	return (tab_cpy);
}
