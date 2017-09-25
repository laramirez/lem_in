/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:23:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 18:07:18 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The ft_printf functions follow four key steps:
**
** 1- "COUNT_ARGS" counts the number of expected arguments in the format string
** (this is needed to know how many varialbe arguments to fetch); if there are
** no arguments, format is taken as is.
**
** 2- "POPULATE_LIST" creates a linked list with each argument, stocking all
** the necessary details needed for conversion and computing (e.g. type, width,
** precision, etc.).
**
** 3- "COMPUTE_AP" fetches variable arguments one by one, converting and
** formatting them into a resulting string (which is stored in the linked list),
** following the information stored for each element by "POPULATE_LIST".
**
** 4- "PRINT_WITH_ARGS" creates a final string that interspaces the original
** format string with the argument strings created by "COMPUTE_AP" in the right
** order, also counting how many characters are copied so the correct value can
** be returned; the resulting string is then printed to standard output
** (for ft_printf), printed to the specified fd (for ft_dprintf) or stored in
** an allocated string (for ft_asprintf).
*/

int			ft_printf(const char *restrict format, ...)
{
	char		*form;
	int			arg_count;
	t_arg		**list;
	t_arg		*tmp;
	va_list		ap;

	form = ft_strdup((char *)format);
	if ((arg_count = count_args(form)) == 0)
		return (print_and_free(form, 1, NULL, 0));
	list = populate_list(form);
	tmp = *list;
	va_start(ap, format);
	while (arg_count && tmp)
	{
		if (tmp->wildcard_1)
			get_arg_opt(tmp, ap);
		if (tmp->wildcard_2)
			get_arg_opt(tmp, ap);
		(tmp->type) ? get_arg(tmp, ap) : special_case(tmp);
		compute_arg(tmp);
		tmp = tmp->next;
		arg_count--;
	}
	va_end(ap);
	return (print_with_args(form, list, 1));
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	char		*form;
	int			arg_count;
	t_arg		**list;
	t_arg		*tmp;
	va_list		ap;

	form = ft_strdup((char *)format);
	if ((arg_count = count_args(form)) == 0)
		return (print_and_free(form, fd, NULL, 0));
	list = populate_list(form);
	tmp = *list;
	va_start(ap, format);
	while (arg_count && tmp)
	{
		if (tmp->wildcard_1)
			get_arg_opt(tmp, ap);
		if (tmp->wildcard_2)
			get_arg_opt(tmp, ap);
		(tmp->type) ? get_arg(tmp, ap) : special_case(tmp);
		compute_arg(tmp);
		tmp = tmp->next;
		arg_count--;
	}
	va_end(ap);
	return (print_with_args(form, list, fd));
}

int			ft_asprintf(char **ret, const char *restrict format, ...)
{
	char		*form;
	int			arg_count;
	t_arg		**list;
	t_arg		*tmp;
	va_list		ap;

	form = ft_strdup(format);
	if ((arg_count = count_args(form)) == 0)
		return (create_str_free(form, ret, NULL, 0));
	list = populate_list(form);
	tmp = *list;
	va_start(ap, format);
	while (arg_count && tmp)
	{
		if (tmp->wildcard_1)
			get_arg_opt(tmp, ap);
		if (tmp->wildcard_2)
			get_arg_opt(tmp, ap);
		(tmp->type) ? get_arg(tmp, ap) : special_case(tmp);
		compute_arg(tmp);
		tmp = tmp->next;
		arg_count--;
	}
	va_end(ap);
	return (create_str_with_args(form, list, ret));
}

int			count_args(char *format)
{
	int		arg_nbr;

	arg_nbr = 0;
	while (*format)
	{
		if (*format == '%')
		{
			arg_nbr++;
			format++;
			while (*format && !is_specifier(*format))
			{
				if (*format == '*')
					arg_nbr++;
				format++;
			}
		}
		format += (*format) ? 1 : 0;
	}
	return (arg_nbr);
}

void		lstdel(t_arg **list)
{
	t_arg	*tmp;
	t_arg	*tmp_next;

	tmp = *list;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->format_code);
		free(tmp->flags);
		free(tmp->width);
		free(tmp->prec);
		free(tmp->mod);
		free(tmp->conv);
		free(tmp->print);
		tmp->next = NULL;
		free(tmp);
		tmp = tmp_next;
	}
	*list = NULL;
	free(list);
}
