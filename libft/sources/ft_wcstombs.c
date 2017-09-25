/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 11:44:58 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:41:39 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_wcstombs(wchar_t *wcs, size_t size)
{
	char	*ret;

	if (!wcs)
		return (NULL);
	if (!ft_wcslen(wcs))
		return (ft_strnew(sizeof(wchar_t)));
	ret = ft_strnew(sizeof(wchar_t));
	while (*wcs && size >= ft_wclen(*wcs))
	{
		ret = ft_strjoinfree(ret, ft_wctomb((wint_t)(*wcs)));
		size -= ft_wclen(*wcs);
		wcs++;
	}
	while (size)
	{
		ret = ft_strjoinfree(ret, ft_strnew(sizeof(wchar_t)));
		size--;
	}
	return (ret);
}
