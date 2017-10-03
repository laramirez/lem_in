/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:47:02 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/02 19:46:03 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		valid_path(t_list *path, size_t end_index)
{
	while (path->next)
		path = path->next;
	if (*(size_t *)path->data == end_index)
		return (1);
	return (0);
}

void		display_paths(t_master *lem_in)
{
	size_t	i;
	t_list	*path_lst;
	t_list	*tmp;

	i = 1;
	path_lst = lem_in->all_paths;
	printf("\n ALL POSSIBLE PATHS\n");
	while (path_lst)
	{
		tmp = ((t_path *)path_lst->data)->itin;
		printf(" ** path %zu **\n", i);
		printf(" cost (%zu): ", ((t_path *)path_lst->data)->cost);
		while (tmp->next)
		{
			printf(" [%zu] --", *(size_t *)tmp->data);
			tmp = tmp->next;
		}
		printf(" [%zu]\n", *(size_t *)tmp->data);
		path_lst = path_lst->next;
		i++;
	}
}

void		add_to_path_list(t_master *lem_in, size_t ant_ID, t_list *path)
{
	t_path	new;

	if (!lem_in)
		return ;
	new.ant_ID = ant_ID;
	new.start_index = *(size_t *)path->data;
	new.itin = path;
	new.cost = ft_lstlen(path) - 1;
	ft_lstaddend(&lem_in->all_paths, ft_lstnew(&new, sizeof(t_path)));
}

void		get_path(t_master *lem_in, size_t start, char *visited)
{
	t_list	*search;
	size_t	i_current;
	t_list	*path;

	path = NULL;
	i_current = start;
	ft_lstaddend(&path, ft_lstnew(&i_current, sizeof(size_t)));
	visited[i_current] = '1';
	while (i_current != lem_in->end_index)
	{
		search = lem_in->tunnels[i_current];
		while (visited[*(size_t *)search->data] == '1')
		{
			search = search->next;
			if (!search)
				break ;
		}
		i_current = *(size_t *)search->data;
		ft_lstaddend(&path, ft_lstnew(&i_current, sizeof(size_t)));
		visited[i_current] = '1';
	}
	if (valid_path(path, lem_in->end_index))
		add_to_path_list(lem_in, 0, path);
	free(visited);
	display_paths(lem_in);
}

void		get_all_paths(t_master *lem_in)
{
	char    *visited;
	visited = ft_create_padding('O', lem_in->room_count);
	get_path(lem_in, lem_in->start_index, visited);
}