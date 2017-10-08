/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:26:49 by lararamirez       #+#    #+#             */
/*   Updated: 2017/10/07 17:35:31 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		find_all_paths(t_master lem_in)
{
	size_t		current_node;
	char		*visited;
	t_stack		*queue;

	queue = NULL;
	current_node = lem_in->start_index;
	visited = ft_create_padding('0', lem_in->room_count);
	visited[current_node] = '1';
	add_possible_paths_to_queue(lem_in, current_node, &visited, &queue);
	
}