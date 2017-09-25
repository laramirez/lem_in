/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_determine_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:59:03 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** These function fill the type fields of each element in the linked list by
** examining the conversion and modifier characters present in the respective
** fields from that element. This step is necessary to fetch the variable
** arguments.
*/

t_arg	*determine_mod_type_3(t_arg *arg)
{
	if (arg->mod[0] == 'j')
	{
		if (ft_match("di", arg->conv))
			arg->type = "intmax_t";
		else if (ft_match("bBoOuUxX", arg->conv))
			arg->type = "uintmax_t";
		else if (ft_match("n", arg->conv))
			arg->type = "intmax_t *";
	}
	else if (arg->mod[0] == 'z')
	{
		if (ft_match("dDibBoOxX", arg->conv))
			arg->type = "long";
		else if (ft_match("uU", arg->conv))
			arg->type = "unsigned long";
	}
	else if (ft_strequ("L", arg->mod))
	{
		if (ft_match("aAeEfFgG", arg->conv))
			arg->type = "long double";
	}
	return (arg);
}

t_arg	*determine_mod_type_2(t_arg *arg)
{
	if (ft_strequ("ll", arg->mod))
	{
		if (ft_match("dDi", arg->conv))
			arg->type = "long long";
		else if (ft_match("bBoOuUxX", arg->conv))
			arg->type = "unsigned long long";
		else if (ft_match("c", arg->conv))
			arg->type = "char";
	}
	else if (ft_match("l", arg->mod))
	{
		if (ft_match("dDi", arg->conv))
			arg->type = "long";
		else if (ft_match("bBoOuUxX", arg->conv))
			arg->type = "unsigned long";
		else if (ft_match("c", arg->conv))
			arg->type = "wint_t";
		else if (ft_match("s", arg->conv))
			arg->type = "wchar_t *";
	}
	else
		return (determine_mod_type_3(arg));
	return (arg);
}

t_arg	*determine_mod_type_1(t_arg *arg)
{
	if (ft_strequ("hh", arg->mod))
	{
		if (ft_match("di", arg->conv))
			arg->type = "signed char";
		else if (ft_match("bBoOuUxX", arg->conv))
			arg->type = "unsigned char";
	}
	else if (ft_strequ("h", arg->mod))
	{
		if (ft_match("di", arg->conv))
			arg->type = "short";
		else if (ft_match("bBoOuUxX", arg->conv))
			arg->type = "unsigned short";
	}
	else
		return (determine_mod_type_2(arg));
	return (arg);
}

t_arg	*determine_type(t_arg *arg)
{
	if (!arg->mod || ft_match("SCDOUp", arg->conv))
	{
		if (arg->conv && ft_match("dibBouxX", arg->conv))
			arg->type = ft_match("di", arg->conv) ? "int" : "unsigned int";
		else if (ft_match("cC", arg->conv))
			arg->type = ft_match("c", arg->conv) ? "char" : "wint_t";
		else if (ft_match("DOU", arg->conv))
			arg->type = ft_match("D", arg->conv) ? "long" : "unsigned long";
		else if (ft_match("aAeEfFgG", arg->conv))
			arg->type = "double";
		else if (ft_match("sS", arg->conv))
			arg->type = ft_match("s", arg->conv) ? "char *" : "wchar_t *";
		else if (ft_match("p", arg->conv))
			arg->type = "void *";
	}
	else if (arg->mod[0] != 'L'
			&& ft_match("aAeEfFgG", arg->conv))
		arg->type = "double";
	else
		return (determine_mod_type_1(arg));
	return (arg);
}
