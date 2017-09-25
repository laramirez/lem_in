/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 11:22:02 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:32:26 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double		ft_pow(double base, double exponent)
{
	if (exponent == 0)
		return (1);
	else if (exponent < 0)
		return (1 / ft_pow(base, -exponent));
	else
		return (base * ft_pow(base, exponent - 1));
}
