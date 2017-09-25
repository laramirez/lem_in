/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 11:01:47 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 20:37:51 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		special_case(int *i_part, char **decimals)
{
	char *tmp;

	*i_part += 1;
	tmp = *decimals;
	*decimals = ft_strdup(*decimals + 1);
	free(tmp);
}

char			*ft_ftoa(double nbr, size_t afterpoint)
{
	int		i_part;
	double	f_part;
	size_t	dec_len;
	char	*decimals;

	if (!afterpoint)
		return (ft_itoa((int)(nbr + 0.5)));
	i_part = (int)nbr;
	if ((f_part = nbr - (float)i_part) == 0)
		decimals = ft_create_padding('0', afterpoint);
	else
	{
		while (afterpoint)
		{
			f_part *= 10;
			afterpoint--;
		}
		dec_len = ft_intlen((int)f_part);
		f_part += 0.5;
		decimals = ft_itoa((int)f_part);
		if (dec_len != ft_intlen((int)f_part))
			special_case(&i_part, &decimals);
	}
	return (ft_strjoinfree(ft_append_after(ft_create_padding('.', 1),
		ft_itoa(i_part)), decimals));
}
