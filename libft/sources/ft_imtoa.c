/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:28:53 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_imtoa(intmax_t n)
{
	char			*number;
	char			is_neg;
	size_t			int_len;
	uintmax_t		nb;

	is_neg = (n < 0) ? 1 : 0;
	nb = ft_abs_intmax(n);
	int_len = ft_intmaxlen(nb) + is_neg;
	if (!(number = ft_strnew(int_len)))
		return (NULL);
	if (n == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[int_len - 1] = nb % 10 + '0';
		int_len--;
		nb /= 10;
	}
	if (is_neg)
		number[0] = '-';
	return (number);
}
