/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:39:16 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:55:03 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			is_modifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	return (0);
}

int			is_specifier(char c)
{
	if (!(c >= '0' && c <= '9') && !(c == ' ' || c == '#' || c == '\'' ||
		c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == ':' ||
			c == '_') && !is_modifier(c) && (ft_isprint(c) || ft_isspace(c)))
		return (1);
	return (0);
}

void		get_flags(t_arg *arg)
{
	char	*format_code;

	format_code = arg->format_code;
	while (*format_code)
	{
		if (*format_code == ' ')
			arg->flags = ft_strjoinfree(arg->flags, ft_create_padding(' ', 1));
		if (*format_code == '#')
			arg->flags = ft_strjoinfree(arg->flags, ft_create_padding('#', 1));
		if (*format_code == '+')
			arg->flags = ft_strjoinfree(arg->flags, ft_create_padding('+', 1));
		if (*format_code == '-')
			arg->flags = ft_strjoinfree(arg->flags, ft_create_padding('-', 1));
		if (*format_code == '0' && !ft_isdigit(*(format_code - 1)))
			arg->flags = ft_strjoinfree(arg->flags, ft_create_padding('0', 1));
		format_code++;
	}
}

void		get_mod(t_arg *arg)
{
	char	*format_code;

	format_code = arg->format_code;
	while (*format_code && !arg->mod)
	{
		if (is_modifier(*format_code))
		{
			if (is_modifier(*(format_code + 1)) &&
				!is_modifier(*(format_code + 2)))
				arg->mod = ft_strsub(format_code, 0, 2);
			else
				arg->mod = ft_strsub(format_code, 0, 1);
		}
		format_code++;
	}
}

int			signed_conversion(char *conv)
{
	if (ft_match("aAdeEfFgGi", conv))
		return (1);
	return (0);
}
