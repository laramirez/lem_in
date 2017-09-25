/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 22:08:32 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char			*number;
	char			is_neg;
	size_t			int_len;
	unsigned int	nb;

	is_neg = (n < 0) ? 1 : 0;
	nb = ft_abs(n);
	int_len = ft_intlen(nb) + is_neg;
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
