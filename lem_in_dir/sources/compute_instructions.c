/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:03:39 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/12 13:09:44 by lararamirez      ###   ########.fr       */
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

void	fill_paths(t_master *lem_in, t_room ***ants)
{
	size_t	ant;

	*ants = (t_room **)ft_memalloc(sizeof(t_room *) * lem_in->ant_count); 
	ant = 0;
	while (ant < lem_in->ant_count)
	{
		(*ants)[ant] = add_path(lem_in);
		ant++;
	}
}

void	free_tab(t_master *lem_in, t_room ***ants)
{
	size_t	ant;
	t_room	*tmp;

	ant = 0;
	while (ant < lem_in->ant_count)
	{
		while ((*ants)[ant])
		{
			tmp = (*ants)[ant];
			(*ants)[ant] = (*ants)[ant]->next;
			free(tmp);
			tmp = NULL;
		}
		free((*ants)[ant]);
		(*ants)[ant] = NULL;
		ant++;
	}
	free(*ants);
	*ants = NULL;
}

void	generate_and_display_instructions(t_master *lem_in)
{
	t_room	**ants;
	t_room	*room;
	size_t	ant_id;
	size_t	count;

	ants = NULL;
	fill_paths(lem_in, &ants);
	ant_id = 0;
	count = 0;
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
	free_tab(lem_in, &ants);
}
