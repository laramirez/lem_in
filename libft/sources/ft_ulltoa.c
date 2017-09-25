/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 16:30:17 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char			*number;
	size_t			longlong_len;

	longlong_len = ft_longlonglen(n);
	number = ft_strnew(longlong_len);
	if (n == 0)
		number[0] = '0';
	while (n > 0)
	{
		number[longlong_len - 1] = n % 10 + '0';
		longlong_len--;
		n /= 10;
	}
	return (number);
}
