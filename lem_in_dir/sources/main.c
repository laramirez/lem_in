/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/26 13:31:34 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		display_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

void		display_rooms(t_master *lem_in)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		printf("room named (%s)	  is at [%zu]\n", lem_in->rooms[i], i);
		i++;
	}
}

void		display_tunnels(t_master *lem_in)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		if (lem_in->tunnels[i])
		{
			printf("Rooms linked to room at [%zu]:", i);
			while (lem_in->tunnels[i]->next)
			{
				printf(" %zu |", *(size_t *)lem_in->tunnels[i]->data);
				lem_in->tunnels[i] = lem_in->tunnels[i]->next;
			}
			printf(" %zu\n", *(size_t *)lem_in->tunnels[i]->data);
		}
		i++;
	}
}

void		initialize_main(t_master *lem_in, t_list **lst, char **line)
{
	lem_in->ant_count = 0;
	lem_in->rooms = NULL;
	lem_in->room_count = 0;
	lem_in->start_index = 0;
	lem_in->end_index = 0;
	lem_in->tunnels = NULL;
	lem_in->instructions = NULL;
	(*lst) = NULL;
	(*line) = NULL;
}

int			main(void)
{
	t_master	lem_in;
	t_list		*lst;
	t_list		*ptr;
	char		*line;

	initialize_main(&lem_in, &lst, &line);
	while (get_next_line(0, &line))
	{
		ft_lstaddend(&lst, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (!lst)
		print_error_and_kill(0);
	if (!get_ant_count((char *)lst->data, &lem_in))
		print_error_and_kill(1);
	if (!count_rooms(lst->next, &lem_in))
		print_error_and_kill(2);
	ptr = get_rooms(lst->next, &lem_in);
	display_rooms(&lem_in);
	printf("start_index is at %zu\n", lem_in.start_index);
	printf("end_index is at %zu\n", lem_in.end_index);
	get_tunnels(ptr, &lem_in);
	display_tunnels(&lem_in);
	// generate_move_instructions(lem_in);
	// ft_printf("\n");
	// display_list(*lem_in.instructions);
	// free everything!
	return (0);
}
