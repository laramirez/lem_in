/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:06:26 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:43:06 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*wcto4bytes(unsigned int value, char *ret)
{
	unsigned int	header_mask_4bytes;
	unsigned int	trailer_mask;

	header_mask_4bytes = 0b11110000;
	trailer_mask = 0b10000000;
	ret[0] = header_mask_4bytes | ((value >> 18) << 29) >> 29;
	ret[1] = trailer_mask | ((value >> 12) << 26) >> 26;
	ret[2] = trailer_mask | ((value >> 6) << 26) >> 26;
	ret[3] = trailer_mask | (value << 26) >> 26;
	return (ret);
}

static char	*wcto3bytes(unsigned int value, char *ret)
{
	unsigned int	header_mask_3bytes;
	unsigned int	trailer_mask;

	header_mask_3bytes = 0b11100000;
	trailer_mask = 0b10000000;
	ret[0] = header_mask_3bytes | ((value >> 12) << 28) >> 28;
	ret[1] = trailer_mask | ((value >> 6) << 26) >> 26;
	ret[2] = trailer_mask | (value << 26) >> 26;
	return (ret);
}

static char	*wcto2bytes(unsigned int value, char *ret)
{
	unsigned int	header_mask_2bytes;
	unsigned int	trailer_mask;

	header_mask_2bytes = 0b11000000;
	trailer_mask = 0b10000000;
	ret[0] = header_mask_2bytes | ((value >> 6) << 27) >> 27;
	ret[1] = trailer_mask | (value << 26) >> 26;
	return (ret);
}

char		*ft_wctomb(wint_t wc)
{
	unsigned int	value;
	int				wc_size;
	char			*ret;

	if (!(wc_size = ft_wclen(wc)) || MB_CUR_MAX < wc_size)
		return (NULL);
	value = wc;
	ret = ft_strnew(wc_size * 2 - 1);
	if (wc_size == 1)
	{
		ret[0] = (unsigned char)value;
		return (ret);
	}
	else if (wc_size == 2)
		return (wcto2bytes(value, ret));
	else if (wc_size == 3)
		return (wcto3bytes(value, ret));
	else if (wc_size == 4)
		return (wcto4bytes(value, ret));
	return (NULL);
}
