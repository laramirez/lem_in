/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_compute_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:21:13 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** These function compute the character strings to be printed, meaning that
** they add formatting and perform conversions based on what the format code
** options ask for.
*/

void		add_width_2(t_arg *arg, char **padding)
{
	if ((((ft_match("xX", arg->conv) || ft_match("bB", arg->conv)) &&
		ft_match("#", arg->flags) && !ft_strequ("0", arg->print)) ||
			ft_match("p", arg->conv)) && ft_match("0", arg->flags))
		arg->print = ft_insert_in_str(*padding, arg->print, 2);
	else if ((arg->print[0] == '-' || arg->print[0] == '+' ||
		arg->print[0] == ' ') && ft_match("0", arg->flags))
		arg->print = ft_insert_in_str(*padding, arg->print, 1);
	else
		arg->print = ft_append_before(*padding, arg->print);
}

char		*add_width(t_arg *arg, char c)
{
	int		len;
	int		width;
	char	*padding;

	len = (arg->is_null) ? 1 : (int)ft_strlen(arg->print);
	width = ft_atoi(arg->width + ((arg->width[0] == '*') ? 1 : 0));
	if (width > len)
	{
		padding = ft_create_padding(c, width - len);
		if (ft_match("-", arg->flags))
		{
			arg->print = ft_strnjoinfree(arg->print, padding, len, width - len);
			if (arg->is_null)
				arg->is_null = width;
		}
		else
			add_width_2(arg, &padding);
	}
	return (arg->print);
}

char		*add_precision(char *print, char *value)
{
	int		len;
	int		precision;

	precision = ft_atoi(value);
	len = ft_strlen(print);
	if ((!precision && !ft_atoi(print)) || !print[0])
		ft_strclr(print);
	else if (print[0] == '-' && precision > (len - 1))
	{
		len--;
		print = ft_insert_in_str(ft_create_padding('0', precision - len),
			print, 1);
	}
	else if (print[0] != '-' && precision > len)
		print = ft_append_before(ft_create_padding('0', precision - len),
			print);
	return (print);
}

void		compute_pbox_args(t_arg *arg, char is_null, char up, char *to_free)
{
	to_free = arg->print;
	if (ft_match("oO", arg->conv))
		arg->print = ft_ultoa_base((unsigned long)ft_atoi(arg->print), 8, up);
	else if (ft_match("pxX", arg->conv))
		arg->print = ft_ultoa_base((unsigned long)ft_atoi(arg->print), 16, up);
	else if (ft_match("bB", arg->conv))
		arg->print = ft_ultoa_base((unsigned long)ft_atoi(arg->print), 2, up);
	free(to_free);
	if (ft_strequ("0", arg->print) && ft_match("xX", arg->conv))
		is_null = 1;
	if (arg->prec)
		arg->print = add_precision(arg->print, arg->prec);
	if ((ft_match("#", arg->flags) || ft_match("p", arg->conv)) && !is_null)
	{
		if (arg->print[0] != '0' && ft_match("oO", arg->conv))
			arg->print = ft_append_before(ft_oct_prefix(), arg->print);
		else if (ft_match("pxX", arg->conv))
			arg->print = ft_append_before(ft_hex_prefix(up), arg->print);
		else if (ft_match("bB", arg->conv))
			arg->print = ft_append_before(ft_bin_prefix(up), arg->print);
	}
	if (arg->width)
		arg->print = add_width(arg, (ft_match("0", arg->flags) &&
			!ft_match("-", arg->flags) && !arg->prec) ? '0' : ' ');
}

void		compute_arg(t_arg *arg)
{
	if (arg->print && ft_match("pbBoOxX", arg->conv))
		compute_pbox_args(arg, arg->is_null, ft_match("BOX", arg->conv) ? 1 : 0,
			NULL);
	else if (arg->conv && !ft_match("sScC", arg->conv))
	{
		if (arg->type && arg->prec && !ft_strequ("double", arg->type) &&
			!ft_strequ("long double", arg->type))
			arg->print = add_precision(arg->print, arg->prec);
		if (ft_match("+", arg->flags) && arg->print[0] != '-' &&
			signed_conversion(arg->conv))
			arg->print = ft_append_before(ft_create_padding('+', 1),
				arg->print);
		else if (ft_match(" ", arg->flags) && arg->print[0] != '-' &&
			signed_conversion(arg->conv))
			arg->print = ft_append_before(ft_create_padding(' ', 1),
				arg->print);
		if (arg->width)
			arg->print = (ft_match("0", arg->flags) &&
				!(ft_match("dui", arg->conv) && arg->prec) &&
					!ft_match("-", arg->flags)) ? add_width(arg, '0') :
						add_width(arg, ' ');
	}
	arg->print_len = ft_strlen(arg->print) + arg->is_null;
}
