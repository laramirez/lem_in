/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:52:13 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_uimtoa(uintmax_t n)
{
	char			*number;
	size_t			long_len;

	long_len = ft_intmaxlen(n);
	number = ft_strnew(long_len);
	if (n == 0)
		number[0] = '0';
	while (n > 0)
	{
		number[long_len - 1] = n % 10 + '0';
		long_len--;
		n /= 10;
	}
	return (number);
}
