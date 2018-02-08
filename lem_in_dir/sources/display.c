/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:33:24 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/08 18:41:14 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		display_paths(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;
	t_list	*path_lst;

	i = 1;
	path_lst = lem_in->all_paths;
	ft_printf("------------------\n");
	ft_printf("ALL POSSIBLE PATHS\n");
	while (path_lst)
	{
		tmp = ((t_path *)path_lst->data)->itin;
		ft_printf("\n** path %zu ** ", i);
		ft_printf("	costs (%zu) moves: ", ((t_path *)path_lst->data)->cost);
		while (tmp->next)
		{
			ft_printf(" [%s] -->", lem_in->rooms[*(size_t *)tmp->data]);
			tmp = tmp->next;
		}
		ft_printf(" [%s]\n", lem_in->rooms[*(size_t *)tmp->data]);
		path_lst = path_lst->next;
		i++;
	}
	ft_printf("------------------\n\n");
}

void		display_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%zu\n", *(size_t *)tmp->data);
		tmp = tmp->next;
	}
}

void		display_rooms(t_master *lem_in)
{
	size_t	i;

	i = 0;
	printf("\n ROOM INDEX\n\n");
	while (i < lem_in->room_count)
	{
		if (i == lem_in->start_index)
			printf("	[%zu] (room name: %s) *start\n", i, lem_in->rooms[i]);
		else if (i == lem_in->end_index)
			printf("	[%zu] (room name: %s) *end\n", i, lem_in->rooms[i]);
		else
			printf("	[%zu] (room name: %s)\n", i, lem_in->rooms[i]);
		i++;
	}
}

void		display_tunnels(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	printf("\n TUNNELS INDEX\n\n");
	while (i < lem_in->room_count)
	{
		if (lem_in->tunnels[i])
		{
			tmp = lem_in->tunnels[i];
			printf("	[%s] >", lem_in->rooms[i]);
			while (tmp->next)
			{
				printf(" [%s] &", lem_in->rooms[*(size_t *)tmp->data]);
				tmp = tmp->next;
			}
			printf(" [%s]\n", lem_in->rooms[*(size_t *)tmp->data]);
		}
		i++;
	}
}

void		display_entry(t_list **lst)
{
	while (*lst)
	{
		ft_printf("%s\n", (*lst)->data);
		(*lst) = (*lst)->next;
	}
}
