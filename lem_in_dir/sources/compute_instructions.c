/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:03:39 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/08 16:45:12 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		print(t_master *lem_in, size_t *ant_id, size_t *count, t_room *room)
{
	ft_printf("L%zu-%s", *ant_id + 1, lem_in->rooms[*(size_t *)room->index]);
	room->received_ant = 1;
	if (*ant_id == *count || *ant_id + 1 == lem_in->ant_count)
	{
		ft_printf("\n");
		if (*ant_id + 1 == lem_in->ant_count &&
			*(size_t *)room->index == lem_in->end_index)
			return (1);
		(*count)++;
		*ant_id = 0;
	}
	else
	{
		ft_printf(" ");
		(*ant_id)++;
	}
	return (0);
}

void	init(size_t *ant_id, size_t *count)
{
	*ant_id = 0;
	*count = 0;
}

void	generate_and_display_instructions(t_master *lem_in)
{
	t_room	*ants[lem_in->ant_count];
	t_room	*room;
	size_t	ant_id;
	size_t	count;

	init(&ant_id, &count);
	while (ant_id < lem_in->ant_count)
	{
		ants[ant_id] = add_path(lem_in);
		ant_id++;
	}
	ant_id = 0;
	while (ant_id < lem_in->ant_count)
	{
		room = ants[ant_id];
		while (room && room->received_ant != 0)
			room = room->next;
		if (!room)
			ant_id++;
		else
		{
			if (print(lem_in, &ant_id, &count, room))
				break ;
		}
	}
}
