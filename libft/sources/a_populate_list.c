/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_populate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:05:24 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** These functions cut up the format into individual arguments which each have,
** potentially, flags, a width, a precision, a modifier and a conversion code.
** All of these are optional except the latter. They each have an individual
** field in the linked list element to be stored in.
*/

void		get_specs_2(char **ptr, char **ptr_2, char *tmp, t_arg *arg)
{
	if (ft_isdigit(**ptr))
	{
		*ptr_2 = *ptr;
		while (ft_isdigit(**ptr))
			(*ptr)--;
		if (**ptr == '.' && !arg->prec)
			arg->prec = ft_strsub(*ptr, 1, *ptr_2 - *ptr);
		else if (**ptr != '.' && !arg->width &&
			!ft_strequ("width", arg->wildcard_1))
		{
			tmp = ft_strsub(*ptr, 1, *ptr_2 - *ptr);
			if (ft_atoi(tmp))
				arg->width = ft_strdup(tmp);
			free(tmp);
		}
	}
	else if (**ptr == '*')
	{
		if (*((*ptr) - 1) == '.')
			arg->wildcard_2 = (arg->prec) ? "void" : "precision";
		else
			arg->wildcard_1 = (arg->width) ? "void" : "width";
		*ptr -= (*((*ptr) - 1) == '.') ? 2 : 1;
	}
}

void		get_specs_1(t_arg *arg)
{
	char	*ptr;
	char	*ptr_2;
	char	*tmp;

	ptr = &arg->format_code[ft_strlen(arg->format_code) - 1];
	ptr_2 = ptr;
	tmp = NULL;
	arg->conv = (is_specifier(*ptr)) ? ft_strdup(ptr) : ft_strnew(0);
	ptr -= (*ptr == '%') ? 1 : 0;
	while (*ptr != '%')
	{
		if (ft_isdigit(*ptr) || *ptr == '*')
			get_specs_2(&ptr, &ptr_2, tmp, arg);
		else if (*ptr == '.' && !arg->prec &&
			!ft_strequ("precision", arg->wildcard_2))
		{
			arg->prec = ft_create_padding('0', 1);
			ptr--;
		}
		else
			ptr--;
	}
}

t_arg		*create_arg(char *format_code)
{
	t_arg	*new_arg;

	new_arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	new_arg->format_code = format_code;
	new_arg->flags = NULL;
	new_arg->width = NULL;
	new_arg->prec = NULL;
	new_arg->mod = NULL;
	new_arg->conv = NULL;
	new_arg->type = NULL;
	new_arg->wildcard_1 = NULL;
	new_arg->wildcard_2 = NULL;
	new_arg->print = NULL;
	new_arg->is_null = 0;
	new_arg->next = NULL;
	if (ft_strequ("%", new_arg->format_code))
		new_arg->print = ft_strnew(0);
	else
	{
		get_flags(new_arg);
		get_mod(new_arg);
		get_specs_1(new_arg);
		determine_type(new_arg);
	}
	return (new_arg);
}

void		add_arg(t_arg **list, t_arg *new_arg)
{
	t_arg	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_arg;
	}
	else
		*list = new_arg;
}

t_arg		**populate_list(char *format)
{
	t_arg	**list;
	char	*ptr;

	ptr = format;
	list = (t_arg **)ft_memalloc(sizeof(t_arg *));
	while (*format && *ptr)
	{
		while (*ptr && *ptr != '%')
			ptr++;
		format = ptr;
		if (*ptr == '%')
		{
			ptr++;
			while (*ptr && !is_specifier(*ptr))
				ptr++;
			(*ptr) ? ptr++ : ptr;
			add_arg(list, create_arg(ft_strsub(format, 0, ptr - format)));
			format = ptr;
		}
	}
	return (list);
}
