/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:52:20 by lramirez          #+#    #+#             */
/*   Updated: 2017/08/09 12:41:25 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*generate_base(int base, short upper)
{
	char				*base_str;
	int					i;
	char				letter;

	i = 0;
	letter = upper ? 'A' : 'a';
	base_str = ft_strnew(base + 1);
	while (i < 10 && i < base)
	{
		base_str[i] = i + 48;
		i++;
	}
	while (i < base)
	{
		base_str[i] = letter;
		letter++;
		i++;
	}
	return (base_str);
}

static char	*reverse_str(char *buffer, char is_neg)
{
	char				*ret;
	size_t				i;
	int					j;

	i = 0;
	j = ft_strlen(buffer);
	ret = ft_strnew(j + is_neg);
	if (is_neg)
	{
		ret[i] = '-';
		i++;
	}
	j -= 1;
	while (j >= 0)
	{
		ret[i] = buffer[j];
		j--;
		i++;
	}
	return (ret);
}

char		*ft_lltoa_base(long long n, int base, short upper)
{
	char				*number;
	unsigned long long	nb;
	char				*base_str;
	char				*buffer;
	size_t				i;

	if (base < 2 || base > 16 || (upper != 0 && upper != 1))
		return (NULL);
	i = 0;
	base_str = generate_base(base, upper);
	nb = ft_abs_longlong(n);
	buffer = ft_strnew(ft_longlonglen(n));
	buffer[0] = '0';
	while (nb > 0)
	{
		buffer[i] = base_str[nb % base];
		i++;
		nb /= base;
	}
	number = reverse_str(buffer, (n < 0) ? 1 : 0);
	free(buffer);
	free(base_str);
	return (number);
}
