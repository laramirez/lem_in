/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tunnels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:26:42 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/25 20:18:06 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	store_tunnel(t_master *lem_in, char *data)
{
	size_t	i;
	
	(!(i = get_room_index(data)))
		return (0);
	i = 0;
	tmp = ft_strsub(data, 0, ft_strchr(data, ' ') - data);
	while (i < lem_in->room_count)
	{
		if (ft_strequ(tmp, lem_in->rooms[i]))
			print_error_and_kill(4);
		i++;
	}
	lem_in->rooms[*n] = tmp;
	(*n)++;
	return (1);
}

void    *get_tunnels(t_list *input, t_master *lem_in)
{
	lem_in->tunnels =
		(t_list **)ft_memalloc(sizeof(t_list *) * lem_in->room_count);
	while (input)
	{
		if (is_tunnel(char *)input->data)
		{
			if (!store_tunnel(lem_in, (char *)input->data))
				break;
		}
		else if ((!is_comment((char *)input->data) &&
			!is_command((char *)input->data)))
			break;
		input = input->next;
	}
}
	// while (input)
	// {
	// 	if (is_tunnel((char *)input->data))
	// 	{
	// 		ptr = ft_strchr((char *)input->data, '-');
	// 		n = get_index(lem_in, ft_strsub((char *)input->data, 0,
	// 			ptr - (char *)input->data));
	// 		if (not_duplicate(lem_in->tunnels[n], ptr + 1))
	// 			ft_lstaddend(&lem_in->tunnels[n], ft_lstnew(ft_strdup(ptr + 1),
	// 				ft_strlen(ptr + 1) + 1));
	// 	}
	// 	else if (!is_comment((char *)input->data) && !is_command((char *)input->data))
	// 		return (0);
	// 	input = input->next;
	// }
	// return (1);

