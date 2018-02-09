/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/09 17:15:42 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		*fill_visited(t_path *path, size_t room_count)
{
	char	*visited;
	t_list	*scan;

	visited = ft_create_padding('0', room_count);
	scan = path->itin;
	while (scan)
	{
		visited[*(size_t *)scan->data] = '1';
		scan = scan->next;
	}
	return (visited);
}

t_list		*add_current_node(t_path *current_path, size_t current_node)
{
	t_list	*new;
	t_list	*scan;

	new = NULL;
	scan = current_path->itin;
	while (scan)
	{
		ft_lstaddend(&new, ft_lstnew((size_t *)scan->data, sizeof(size_t)));
		scan = scan->next;
	}
	ft_lstaddend(&new, ft_lstnew(&current_node, sizeof(size_t)));
	return (new);
}

char		queue_possible_paths(t_master *lem_in, size_t current_node,
				t_path *current_path, t_stack *queue)
{
	t_list	*tunnels;
	t_path	*new_path;
	size_t	count;

	tunnels = lem_in->tunnels[current_node];
	new_path = NULL;
	count = 0;
	while (tunnels)
	{
		if ((current_path->visited)[*(size_t *)tunnels->data] == '0')
		{
			current_node = *(size_t *)tunnels->data;
			(current_path->visited)[current_node] = '1';
			new_path = (t_path *)ft_memalloc(sizeof(t_path));
			new_path->itin = add_current_node(current_path, current_node);
			new_path->visited = fill_visited(new_path, lem_in->room_count);
			new_path->last_node = current_node;
			new_path->cost = ft_lstlen(new_path->itin) - 1;
			init_queue(new_path);
			pile_onto_stack(new_path, queue);
			count++;
		}
		tunnels = tunnels->next;
	}
	return (count);
}

void		find_paths(t_master *lem_in, size_t start)
{
	size_t		current_node;
	t_path		*current_path;
	t_stack		*queue;

	current_node = start;
	initialize_find_paths(&current_path, &queue, lem_in->room_count);
	ft_lstaddend(&current_path->itin, ft_lstnew(&current_node, sizeof(size_t)));
	current_path->last_node = current_node;
	(current_path->visited)[current_node] = '1';
	if (!queue_possible_paths(lem_in, current_node, current_path, queue))
		print_process_error_and_kill(0);
	while (queue->size)
	{
		current_node = queue->bottom->last_node;
		if (!(current_node == lem_in->end_index))
		{
			queue_possible_paths(lem_in, current_node, queue->bottom, queue);
			pop_off_bottom_queue(queue);
		}
		else
			move_to_path_lst(lem_in, queue);
	}
}
