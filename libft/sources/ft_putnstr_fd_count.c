/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 21:57:33 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:40:48 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putnstr_fd_count(char *s, size_t n, int fd)
{
	if (!n)
		return (0);
	write(fd, s, n);
	return ((int)n);
}
