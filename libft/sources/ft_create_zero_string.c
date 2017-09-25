/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_zero_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 12:58:27 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 17:34:15 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_create_zero_string(void)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = '\\';
	str[1] = '0';
	return (str);
}
