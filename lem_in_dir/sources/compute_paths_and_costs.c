/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_paths_and_costs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/04 14:12:50 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_queue(t_stack **queue)
{
	t_stack *tmp;

	tmp = *queue;
	while (tmp)
	{
		printf("[%zu] from [%zu]\n", tmp->room, tmp->previous_room);
		tmp = tmp->next;
	}
}

void		display_paths(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;
	t_list	*path_lst;

	i = 1;
	path_lst = lem_in->paths_lst;
	printf("\n ALL POSSIBLE PATHS\n");
	while (path_lst)
	{
		tmp = ((t_path *)path_lst->data)->itin;
		printf("\n ** path %zu ** ", i);
		printf(" cost (%zu): ", ((t_path *)path_lst->data)->cost);
		while (tmp->next)
		{
			printf(" [%zu] --", *(size_t *)tmp->data);
			tmp = tmp->next;
		}
		printf(" [%zu]\n\n", *(size_t *)tmp->data);
		path_lst = path_lst->next;
		i++;
	}
}

void		pile_onto_stack(size_t current_node, size_t adj_node, t_stack **queue)
{
	t_stack		*new;
	
	new = (t_stack *)ft_memalloc(sizeof(t_stack));
	new->room = adj_node;
	new->previous_room = current_node;
	new->next = *queue;
	*queue = new;
}

char        add_adj_nodes_to_queue(t_master *lem_in, size_t current_node,
				char *visited, t_stack **queue)
{
	size_t	count;
	t_list	*tunnels;

	count = 0;
	tunnels = lem_in->tunnels[current_node];
	visited[current_node] = '1';
	while (tunnels)
	{
		if (visited[*(size_t *)tunnels->data] == '0')
		{
			pile_onto_stack(current_node, *(size_t *)tunnels->data, queue);
			count++;
		}
		tunnels = tunnels->next;
	}
	if (count)
		return (1);
	return (0);
}

void		add_to_path_lst(t_master *lem_in, t_list **path)
{
	t_path	*new_path;
	t_path	*test;

	new_path = (t_path *)ft_memalloc(sizeof(t_path));
	new_path->itin = *path;
	new_path->cost = ft_lstlen(*path) - 1;
	ft_lstaddend(&lem_in->paths_lst, ft_lstnew(new_path, sizeof(t_path)));
	test = (t_path *)lem_in->paths_lst->data;
}

size_t		pop_off_queue(t_stack **queue)
{
	t_stack		*to_free;
	size_t		ret;
	
	ret = (*queue)->room;
	to_free = *queue;
	*queue = (*queue)->next;
	free(to_free);
	return (ret);
}

char		valid_path(t_list *path, size_t end_index)
{
	while (path->next)
		path = path->next;
	if (*(size_t *)path->data == end_index)
		return (1);
	return (0);
}

void		backtrack_to_next_in_queue(t_list *path, t_stack **queue);





void		compute_paths_and_costs(t_master *lem_in)
{
	t_stack *queue;
	t_list	*path;
	size_t  current_node;
	char    *visited;

	queue = NULL;
	path = NULL;
	current_node = lem_in->start_index;
	visited = ft_create_padding('0', lem_in->room_count);
	while (add_adj_nodes_to_queue(lem_in, current_node, visited, &queue))
	{
		ft_lstaddend(&path, ft_lstnew(&current_node, sizeof(size_t)));
		current_node = pop_off_queue(&queue);
	}
	ft_lstaddend(&path, ft_lstnew(&current_node, sizeof(size_t)));
	if (valid_path(path, lem_in->end_index))
		add_to_path_lst(lem_in, &path);
	backtrack_to_next_in_queue(path, &queue)

	// print_queue(&queue);
	// while ( )
	// {
	// 	get_path(lem_in, lem_in->start_index, &visited, &i_divert);
	// 	display_paths(lem_in);
	// }
	// free(visited);
	display_paths(lem_in);	
}