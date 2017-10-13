/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:23:46 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/13 12:32:42 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	is_number(char *str)
{
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

char	is_room(char *str)
{
	char	*tmp;

	tmp = str;
	if (*str == 'L' || *str == '#')
		return (0);
	while (!(*tmp == ' '))
	{
		if (!ft_isprint(*tmp) || (*tmp == '\0'))
			return (0);
		tmp++;
	}
	if (tmp == str)
		return (0);
	if (!check_coordinates(tmp + 1))
		return (0);
	return (1);
}

char	is_comment(char *str)
{
	if (*str == '#' && *(str + 1) != '#')
		return (1);
	else
		return (0);
}

char	is_command(char *str)
{
	if (*str == '#' && *(str + 1) == '#' &&
		!ft_strequ("##start", str) &&
			!ft_strequ("##end", str))
		return (1);
	else
		return (0);
}

char	is_tunnel(char *str)
{
	if (!ft_isprint(*str) || *str == '-' || *str == ' ')
		return (0);
	while (ft_isprint(*str) && *str != '-' && *str != ' ')
		str++;
	if (*str != '-')
		return (0);
	str += 1;
	if (!ft_isprint(*str) || *str == '-' || *str == ' ')
		return (0);
	while (ft_isprint(*str) && *str != '-' && *str != ' ')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}
