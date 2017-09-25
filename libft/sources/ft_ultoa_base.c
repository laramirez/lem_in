/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:34:02 by lararamirez       #+#    #+#             */
/*   Updated: 2017/08/29 18:42:03 by lramirez         ###   ########.fr       */
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

static char	*reverse_str(char *buffer)
{
	char				*ret;
	size_t				i;
	int					j;

	i = 0;
	j = ft_strlen(buffer);
	ret = ft_strnew(j);
	j -= 1;
	while (j >= 0)
	{
		ret[i] = buffer[j];
		j--;
		i++;
	}
	return (ret);
}

char		*ft_ultoa_base(unsigned long n, int base, short upper)
{
	size_t				i;
	char				*number;
	char				*base_str;
	char				buffer[30];

	if (base < 2 || base > 16 || (upper != 0 && upper != 1))
		return (NULL);
	i = 0;
	base_str = generate_base(base, upper);
	buffer[0] = '0';
	while (n > 0)
	{
		buffer[i] = base_str[n % (unsigned long)base];
		i++;
		n /= (unsigned long)base;
	}
	buffer[(i) ? i : 1] = '\0';
	number = reverse_str(buffer);
	free(base_str);
	return (number);
}
