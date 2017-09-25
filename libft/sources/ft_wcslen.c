/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:56:38 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:41:22 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the number of total bytes occupied by wcs.
*/

size_t		ft_wcslen(wchar_t *wcs)
{
	size_t	len;

	len = 0;
	while (*wcs)
	{
		if (!ft_wclen(*wcs))
			return (0);
		len += ft_wclen(*wcs);
		wcs++;
	}
	return (len);
}
