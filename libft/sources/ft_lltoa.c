/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 16:24:13 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_lltoa(long long n)
{
	char				*number;
	char				is_neg;
	size_t				longlong_len;
	unsigned long long	nb;

	is_neg = (n < 0) ? 1 : 0;
	nb = ft_abs_longlong(n);
	longlong_len = ft_longlonglen(nb) + is_neg;
	if (!(number = ft_strnew(longlong_len)))
		return (NULL);
	if (n == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[longlong_len - 1] = nb % 10 + '0';
		longlong_len--;
		nb /= 10;
	}
	if (is_neg)
		number[0] = '-';
	return (number);
}
