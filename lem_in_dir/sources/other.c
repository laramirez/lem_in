/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:43:28 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/25 19:00:51 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	count_rooms(t_list *input, t_master *lem_in)
{
	while (input)
	{
		if (is_room((char *)input->data))
			lem_in->room_count++;
		else if (!is_comment((char *)input->data) &&
			!is_command((char *)input->data) &&
				!ft_strequ("##start", (char *)input->data) &&
					!ft_strequ("##end", (char *)input->data))
			break;
		input = input->next;		
	}
	if (lem_in->room_count == 0)
		return (0);
	lem_in->rooms = (char **)ft_memalloc(sizeof(char *) * lem_in->room_count);
	return (1);
}

size_t	get_index(t_master *lem_in, char *name)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		if (ft_strequ(lem_in->rooms[i], name))
		{
			free(name);
			return (i);
		}
		i++;
	}
	free(name);
	return (0);
}

char	not_duplicate(t_list *room, char *name)
{
	while (room)
	{
		if (ft_strequ(name, (char *)room->data))
			return (0);
		room = room->next;
	}
	return (1);
}

char	get_ant_count(char *data, t_master *lem_in)
{
	long	ant_count;
	
	if (is_number(data) && (ant_count = ft_atoi(data)) > 0 &&
		ant_count <= LONG_MAX)
		lem_in->ant_count = (size_t)ant_count;
	else
		return (0);
	return (1);
}
