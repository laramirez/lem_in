/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_intmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:30:39 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

uintmax_t		ft_abs_intmax(intmax_t nbr)
{
	uintmax_t nb;

	if (nbr < 0)
	{
		nb = (uintmax_t)-nbr;
		return (nb);
	}
	return (nbr);
}
