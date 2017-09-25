/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:25 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/04 11:34:28 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_countwords(char const *str, char c)
{
	size_t	count;
	int		token;

	count = 0;
	token = 0;
	while (*str)
	{
		if (token == 0 && *str != c)
		{
			count++;
			token = 1;
		}
		if (token == 1 && *str == c)
			token = 0;
		str++;
	}
	return (count);
}
