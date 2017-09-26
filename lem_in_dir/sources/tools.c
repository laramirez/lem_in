/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:23:46 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/25 18:57:28 by lararamirez      ###   ########.fr       */
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

char	check_coordinates(char **str, char **tmp, char *coordinates)
{
	(*tmp) += 1;
	(*str) = (*tmp);
	while (!(**tmp == ' '))
	{
		if (**tmp == '\0')
		{
			if (*coordinates == 1 && (*tmp != *str))
				break ;
			else
				return (0);
		}
		else if (!ft_isdigit(**tmp))
			return (0);
		(*tmp)++;
	}
	if (*str == *tmp)
		return (0);
	return (1);
}

char	is_room(char *str)
{
	char	*tmp;
	char	coordinates;
	
	tmp = str;
	coordinates = 2;
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
	while (coordinates)
	{
		if (!check_coordinates(&str, &tmp, &coordinates))
			return (0);
		coordinates -= 1;
	}
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
