/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_quicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:14:43 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 16:37:58 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		partition(int *tab, int start, int end)
{
	int	i_pivot;
	int	i;
	int	pivot;
	int	tmp;

	pivot = tab[end];
	i_pivot = start;
	i = start;
	while (i < end)
	{
		if (tab[i] <= pivot)
		{
			tmp = tab[i];
			tab[i] = tab[i_pivot];
			tab[i_pivot] = tmp;
			i_pivot++;
		}
		i++;
	}
	tmp = tab[i_pivot];
	tab[i_pivot] = tab[end];
	tab[end] = tmp;
	return (i_pivot);
}

void			ft_tab_quicksort(int *tab, int start, int end)
{
	int	i_pivot;

	if (start < end)
	{
		i_pivot = partition(tab, start, end);
		ft_tab_quicksort(tab, start, i_pivot - 1);
		ft_tab_quicksort(tab, i_pivot + 1, end);
	}
}
