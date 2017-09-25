/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:52:47 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long	ft_abs_long(long n)
{
	unsigned long nb;

	if (n < 0)
	{
		nb = (unsigned long)-n;
		return (nb);
	}
	return (n);
}
