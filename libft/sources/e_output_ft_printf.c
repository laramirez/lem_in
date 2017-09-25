/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_output_ft_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 21:11:08 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/11 17:50:19 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		print_and_free(char *format, int fd, t_arg **list, long n)
{
	if (list)
		lstdel(list);
	if (n < 0)
	{
		free(format);
		return (-1);
	}
	if (!n)
		n = (long)ft_strlen(format);
	ft_putnstr_fd_count(format, n, fd);
	free(format);
	return (n);
}

int		error(char *to_free, char *print_result, int fd, t_arg **list)
{
	free(to_free);
	return (print_and_free(print_result, fd, list, -1));
}

void	format_part(char **ptr, char **print_result, long *n, char **format)
{
	while (**ptr && **ptr != '%')
		(*ptr)++;
	*print_result = ft_strnjoinfree(*print_result,
	ft_strsub(*format, 0, *ptr - *format), *n, *ptr - *format);
	*n += (*ptr - *format);
	*format = *ptr;
}

void	arg_part(char **ptr, char **print_result, long *n, t_arg *tmp)
{
	(*ptr)++;
	while (**ptr && !is_specifier(**ptr))
		(*ptr)++;
	*print_result = ft_strnjoinfree(*print_result, ft_strdup(tmp->print), *n,
		tmp->print_len);
	*n += tmp->print_len;
	(*ptr) += (**ptr) ? 1 : 0;
}

int		print_with_args(char *format, t_arg **list, int fd)
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
				return (error(to_free, print_result, fd, list));
			arg_part(&ptr, &print_result, &n, tmp);
			tmp = tmp->next;
			format = ptr;
		}
	}
	free(to_free);
	return (print_and_free(print_result, fd, list, n));
}
