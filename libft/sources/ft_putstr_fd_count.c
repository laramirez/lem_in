/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 21:57:43 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/18 21:57:49 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_putstr_fd_count(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
	return ((int)ft_strlen(str));
}
