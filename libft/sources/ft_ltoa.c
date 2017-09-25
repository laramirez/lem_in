/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:41:20 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ltoa(long n)
{
	char			*number;
	char			is_neg;
	size_t			long_len;
	unsigned long	nb;

	is_neg = (n < 0) ? 1 : 0;
	nb = ft_abs_long(n);
	long_len = ft_longlen(nb) + is_neg;
	if (!(number = ft_strnew(long_len)))
		return (NULL);
	if (n == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[long_len - 1] = nb % 10 + '0';
		long_len--;
		nb /= 10;
	}
	if (is_neg)
		number[0] = '-';
	return (number);
}
