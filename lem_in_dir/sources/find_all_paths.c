/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:47:02 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/02 13:41:35 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		get_all_paths_and_cost(t_master *lem_in)
{
	char    *visited;
	t_list	*search;
	size_t	i_current;
	t_list	**path;

	path = (t_list **)ft_memalloc(sizeof(t_list *));
	visited = ft_create_padding('O', lem_in->room_count);
	i_current = 6;
	ft_lstaddend(path, ft_lstnew(&i_current, sizeof(size_t)));
	visited[i_current] = '1';
	search = lem_in->tunnels[i_current];
	printf("i_current is %zu\n", i_current);
	printf("data %zu\n", *(size_t *)search->data);
	while (i_current != lem_in->end_index && search)
	{
		if (visited[*(size_t *)search->data] == '1')
			search = search->next;
		if (!search)
			break ;
		else
		{
			ft_lstaddend(path, ft_lstnew(&i_current, sizeof(size_t)));
			i_current = *(size_t *)search->data;
			visited[i_current] = '1';
		}
	}
	printf("PATH 1\n");
	display_list(*path);
}