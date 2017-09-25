/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_output_ft_asprintf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:03:42 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		create_str_free(char *format, char **ret, t_arg **list, long n)
{
	if (list)
		lstdel(list);
	if (n < 0 || !ret)
	{
		free(format);
		return (-1);
	}
	if (!n)
		n = (long)ft_strlen(format);
	*ret = ft_strnew(n);
	ft_memcpy(*ret, format, n);
	free(format);
	return ((int)n);
}

int		error_as(char *to_free, char *print_result, char **ret, t_arg **list)
{
	free(to_free);
	return (create_str_free(print_result, ret, list, -1));
}

int		create_str_with_args(char *format, t_arg **list, char **ret)
{
	long	n;
	char	*to_free;
	char	*ptr;
	char	*print_result;
	t_arg	*tmp;

	n = 0;
	to_free = format;
	ptr = format;
	print_result = NULL;
	tmp = *list;
	while (*ptr && *format)
	{
		format_part(&ptr, &print_result, &n, &format);
		if (*ptr == '%' && tmp)
		{
			if (!tmp->print)
				return (error_as(to_free, print_result, ret, list));
			arg_part(&ptr, &print_result, &n, tmp);
			tmp = tmp->next;
			format = ptr;
		}
	}
	free(to_free);
	return (create_str_free(print_result, ret, list, n));
}
