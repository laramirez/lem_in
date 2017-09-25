/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:18:49 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** These function fetch the variable arguments one by one and converts them to
** a character string, stocked in the linked list for printing.
*/

void		get_s_arg(t_arg *arg, va_list ap)
{
	wchar_t	*wcs;

	if (ft_strequ("char *", arg->type))
	{
		if (!(arg->print = ft_strdup(va_arg(ap, char *))))
			arg->print = ft_create_null_string();
		if (arg->prec)
			arg->print = ft_strsubfree(arg->print, 0, ft_atoi(arg->prec));
	}
	else if (ft_strequ("wchar_t *", arg->type))
	{
		wcs = va_arg(ap, wchar_t *);
		if (!wcs)
			arg->print = ft_create_null_string();
		else
			arg->print = ft_wcstombs(wcs, (arg->prec) ?
				(size_t)ft_atoi(arg->prec) : ft_wcslen(wcs));
		if (arg->prec)
			arg->print = ft_strsubfree(arg->print, 0, ft_atoi(arg->prec));
	}
	if (arg->width)
		arg->print = (ft_match("0", arg->flags) &&
			!ft_match("-", arg->flags)) ? add_width(arg, '0') :
				add_width(arg, ' ');
}

void		get_arg_2(t_arg *arg, va_list ap)
{
	if (ft_strequ("unsigned long", arg->type) ||
		ft_strequ("size_t", arg->type) || ft_strequ("void *", arg->type))
		arg->print = ft_ultoa(va_arg(ap, unsigned long));
	else if (ft_strequ("char", arg->type) || ft_strequ("wint_t", arg->type))
	{
		if (ft_strequ("char", arg->type))
			arg->print = ft_create_padding((char)va_arg(ap, int), 1);
		else if (ft_strequ("wint_t", arg->type))
			arg->print = ft_wctomb(va_arg(ap, wint_t));
		if (arg->print && arg->print[0] == 0)
			arg->is_null = 1;
		if (arg->print && arg->width)
			arg->print = (ft_match("0", arg->flags) &&
			!ft_match("-", arg->flags)) ? add_width(arg, '0') :
			add_width(arg, ' ');
	}
	else if (ft_strequ("char *", arg->type) ||
		ft_strequ("wchar_t *", arg->type))
		get_s_arg(arg, ap);
	else if (ft_strequ("double", arg->type) ||
		ft_strequ("long double", arg->type))
		arg->print = (arg->prec) ? ft_dtoa(va_arg(ap, double),
			ft_atoi(arg->prec)) : ft_dtoa(va_arg(ap, double), 6);
	else
		arg->print = ft_strnew(0);
}

void		get_arg(t_arg *arg, va_list ap)
{
	if (ft_strequ("signed char", arg->type))
		arg->print = ft_itoa((signed char)va_arg(ap, int));
	else if (ft_strequ("unsigned char", arg->type))
		arg->print = ft_itoa((unsigned char)va_arg(ap, int));
	else if (ft_strequ("short", arg->type))
		arg->print = ft_itoa((short)va_arg(ap, int));
	else if (ft_strequ("unsigned short", arg->type))
		arg->print = ft_itoa((unsigned short)va_arg(ap, int));
	else if (ft_strequ("int", arg->type))
		arg->print = ft_itoa(va_arg(ap, int));
	else if (ft_strequ("unsigned int", arg->type))
		arg->print = ft_uitoa(va_arg(ap, unsigned int));
	else if (ft_strequ("intmax_t", arg->type))
		arg->print = ft_imtoa(va_arg(ap, intmax_t));
	else if (ft_strequ("uintmax_t", arg->type))
		arg->print = ft_uimtoa(va_arg(ap, uintmax_t));
	else if (ft_strequ("long", arg->type))
		arg->print = ft_ltoa(va_arg(ap, long));
	else if (ft_strequ("long long", arg->type))
		arg->print = ft_lltoa(va_arg(ap, long long));
	else if (ft_strequ("unsigned long long", arg->type))
		arg->print = ft_ulltoa(va_arg(ap, unsigned long long));
	else
		get_arg_2(arg, ap);
}

void		get_arg_opt(t_arg *arg, va_list ap)
{
	int		opt_arg;

	opt_arg = va_arg(ap, int);
	if (!arg->width && ft_strequ("width", arg->wildcard_1))
		arg->width = ft_ltoa(ft_abs(opt_arg));
	else if (!arg->prec && ft_strequ("precision", arg->wildcard_2) &&
		opt_arg >= 0)
		arg->prec = ft_ltoa(opt_arg);
	if (opt_arg < 0 && arg->wildcard_1 && !ft_match("-", arg->flags))
		arg->flags = (arg->flags) ?
			ft_append_after(ft_create_padding('-', 1), arg->flags) :
				ft_create_padding('-', 1);
}

void		special_case(t_arg *arg)
{
	if (arg->conv)
		arg->print = ft_strdup(arg->conv);
	else
		arg->print = ft_strnew(0);
}
