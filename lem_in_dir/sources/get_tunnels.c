/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tunnels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:26:42 by lararamirez       #+#    #+#             */
/*   Updated: 2018/02/12 10:39:11 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t	get_room_index(t_master *lem_in, char *room_name)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		if (ft_strequ(lem_in->rooms[i], room_name))
			return (i);
		i++;
	}
	return (i);
}

char	not_duplicate_tunnel(t_list *tunnel_lst, size_t i)
{
	while (tunnel_lst)
	{
		if ((size_t)tunnel_lst->data == i)
			return (0);
		tunnel_lst = tunnel_lst->next;
	}
	return (1);
}

char	add_to_list_at_index(t_master *lem_in, char *adj_room, size_t i)
{
	size_t	adj_i;

	if ((adj_i = get_room_index(lem_in, adj_room)) == lem_in->room_count)
		return (0);
	if (not_duplicate_tunnel(lem_in->tunnels[i], adj_i))
		ft_lstaddend(&lem_in->tunnels[i], ft_lstnew(&adj_i, sizeof(size_t)));
	if (not_duplicate_tunnel(lem_in->tunnels[adj_i], i))
		ft_lstaddend(&lem_in->tunnels[adj_i], ft_lstnew(&i, sizeof(size_t)));
	return (1);
}

char	store_tunnel(t_master *lem_in, char *data)
{
	size_t	i;
	char	*tmp;

	tmp = ft_strsub(data, 0, ft_strchr(data, '-') - data);
	if ((i = get_room_index(lem_in, tmp)) == lem_in->room_count ||
		!add_to_list_at_index(lem_in, ft_strchr(data, '-') + 1, i))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

void	get_tunnels(t_list *input, t_master *lem_in)
{
	t_list	*prev;

	lem_in->tunnels =
		(t_list **)ft_memalloc(sizeof(t_list *) * lem_in->room_count);
	prev = input;
	while (input)
	{
		if (is_tunnel((char *)input->data))
		{
			if (!store_tunnel(lem_in, (char *)input->data))
			{
				stop_input(&prev, &input);
				break ;
			}
		}
		else if ((!is_comment((char *)input->data) &&
			!is_command((char *)input->data)))
		{
			stop_input(&prev, &input);
			break ;
		}
		prev = input;
		input = input->next;
	}
}
