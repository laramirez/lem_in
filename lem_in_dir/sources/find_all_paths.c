/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:47:02 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/03 15:43:32 by lramirez         ###   ########.fr       */
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

size_t		reset_visited(t_list *path, char **visited)
{
	t_list	*tmp;
	
	tmp = path;
	while(tmp->next->next)
	{
		(*visited)[*(size_t *)tmp->data] = '0';
		tmp = tmp->next;
	}
	(*visited)[*(size_t *)tmp->next->data] = '0';
	return (*(size_t *)tmp->data);
}

void		get_path(t_master *lem_in, size_t start, char **visited, size_t *i_divert)
{
	t_list	*search;
	size_t	i_current;
	t_list	*path;

	path = NULL;
	i_current = start;
	ft_lstaddend(&path, ft_lstnew(&i_current, sizeof(size_t)));
	(*visited)[i_current] = '1';
	while (i_current != lem_in->end_index)
	{
		search = lem_in->tunnels[i_current];
		printf("i_current is [%zu]\n", i_current);
		while ((*visited)[*(size_t *)search->data] == '1' && search)
		{
			if (*(size_t *)search->data == *i_divert && *i_divert != start)
				(*visited)[*(size_t *)search->data] = '0';
			printf("i_divert [%zu]\n", *i_divert);
			printf("[%zu]\n", *(size_t *)search->data);
			printf("[%s]\n", *visited);
			search = search->next;
		}
		if (!search)
			break ;
		i_current = *(size_t *)search->data;
		ft_lstaddend(&path, ft_lstnew(&i_current, sizeof(size_t)));
		(*visited)[i_current] = '1';
	}
	if (valid_path(path, lem_in->end_index))
		add_to_path_list(lem_in, 0, path);
	(*visited)[*i_divert] = '1';
	if (!unvisited_nodes(*visited))
		return ;
	*i_divert = reset_visited(path, visited);
}

char		unvisited_nodes(char *visited)
{
	while (visited)
	{
		if (*visited == '0')
			return (1);
		visited++;
	}
	return (0);
}

void		get_all_paths(t_master *lem_in)
{
	char    *visited;
	size_t	i_divert;

	i_divert = lem_in->start_index;
	visited = ft_create_padding('0', lem_in->room_count);
	while (unvisited_nodes(visited))
	{
		get_path(lem_in, lem_in->start_index, &visited, &i_divert);
		display_paths(lem_in);
	}
	free(visited);
	display_paths(lem_in);	
}