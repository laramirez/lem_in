/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:12:52 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:38:49 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_wclen(wint_t wc)
{
	unsigned int	value;

	value = wc;
	if (value >= 0xD800 && value <= 0xDFFF)
		return (0);
	else if (value <= 0x7F)
		return (1);
	else if (value <= 0x7FF)
		return (2);
	else if (value <= 0xFFFF)
		return (3);
	else if (value <= 0x10FFFF)
		return (4);
	else
		return (0);
}
