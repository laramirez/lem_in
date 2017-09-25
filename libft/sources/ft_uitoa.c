/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 16:13:53 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_uitoa(unsigned int n)
{
	char			*number;
	size_t			int_len;

	int_len = ft_intlen(n);
	number = ft_strnew(int_len);
	if (n == 0)
		number[0] = '0';
	while (n > 0)
	{
		number[int_len - 1] = n % 10 + '0';
		int_len--;
		n /= 10;
	}
	return (number);
}
