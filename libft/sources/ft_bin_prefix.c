/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:57:59 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/17 11:58:33 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_bin_prefix(char upper)
{
	char	*ret;

	ret = ft_strnew(2);
	ret[0] = '0';
	ret[1] = (upper) ? 'B' : 'b';
	return (ret);
}
