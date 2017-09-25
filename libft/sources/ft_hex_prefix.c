/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:59:47 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_hex_prefix(char upper)
{
	char	*ret;

	ret = ft_strnew(2);
	ret[0] = '0';
	ret[1] = (upper) ? 'X' : 'x';
	return (ret);
}
