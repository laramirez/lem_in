/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:33:11 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/09 17:36:51 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_append_before(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(new, s1);
	ft_strcpy(&new[ft_strlen(s1)], s2);
	free(s1);
	free(s2);
	return (new);
}
