/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:33:24 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/10 18:09:47 by lramirez         ###   ########.fr       */
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
	ft_printf("\n\n \033[1;33mALL POSSIBLE PATHS\033[0m\n");
	while (path_lst)
	{
		tmp = ((t_path *)path_lst->data)->itin;
		ft_printf("\n \033[1;36m** path %zu ** ", i);
		ft_printf("	\033[0mcosts (\033[1;31m%zu\033[0m) moves\033[0;36m ",
			((t_path *)path_lst->data)->cost);
		while (tmp->next)
		{
			ft_printf(" [%s] -->", lem_in->rooms[*(size_t *)tmp->data]);
			tmp = tmp->next;
		}
		ft_printf(" [%s]\033[0m\n", lem_in->rooms[*(size_t *)tmp->data]);
		path_lst = path_lst->next;
		i++;
	}
	ft_printf("\n\n");
}

void		display_rooms(t_master *lem_in)
{
	size_t	i;

	i = 0;
	ft_printf("\n \033[1;33mROOM INDEX\033[0m\n\n");
	while (i < lem_in->room_count)
	{
		if (i == lem_in->start_index)
		{
			ft_printf("	\033[1;36m[%zu]\033[0m room name: \033[0;36m", i);
			ft_printf("%s \033[1;31m*start\033[0m\n\n", lem_in->rooms[i]);
		}
		else if (i == lem_in->end_index)
		{
			ft_printf("	\033[1;36m[%zu]\033[0m room name: \033[0;36m", i);
			ft_printf("%s \033[1;31m*end\033[0m\n\n", lem_in->rooms[i]);
		}
		else
		{
			ft_printf("	\033[1;36m[%zu]\033[0m room name: \033[0;36m", i);
			ft_printf("%s\033[0m\n\n", lem_in->rooms[i]);
		}
		i++;
	}
}

void		display_tunnels(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	printf("\n \033[1;33mTUNNELS\033[0m\n\n");
	while (i < lem_in->room_count)
	{
		if (lem_in->tunnels[i])
		{
			tmp = lem_in->tunnels[i];
			printf("	\033[1;36m[%s]\033[0m >", lem_in->rooms[i]);
			while (tmp->next)
			{
				printf(" \033[0;36m[%s]", lem_in->rooms[*(size_t *)tmp->data]);
				printf("\033[0m &\033[0;36m");
				tmp = tmp->next;
			}
			printf(" [%s]\033[0m\n\n", lem_in->rooms[*(size_t *)tmp->data]);
		}
		i++;
	}
}

void		display_entry(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}
