/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_paths_and_costs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/04 17:52:40 by lararamirez      ###   ########.fr       */
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

void		reset_visited(char **visited)
{
	size_t	i;

	i = 0;
	while ((*visited)[i])
	{
		(*visited)[i] = '0';
		i++;
	}
}

void		delete_lst(t_list **path)
{
	t_list	*tmp;
	t_list	*tmp_next;
	
	tmp = *path;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*path = NULL;
}

size_t		backtrack_to_queued(t_list **path, t_stack **queue,
				char **visited, size_t end_index)
{
	t_list	*new_path;
	t_list	*tmp;
	size_t	target_node;
	size_t	count;

	new_path = NULL;
	count = 3;
	reset_visited(visited);
	tmp = *path;
	target_node = (*queue)->previous_room;
	while (*(size_t *)tmp->data != target_node && count)
	{
		ft_lstaddend(&new_path, ft_lstnew((size_t *)tmp->data, sizeof(size_t)));
		(*visited)[*(size_t *)tmp->data] = '1';
		tmp = tmp->next;
		count--;
	}
	ft_lstaddend(&new_path, ft_lstnew((size_t *)tmp->data, sizeof(size_t)));
	(*visited)[*(size_t *)tmp->data] = '1';
	(*visited)[*(size_t *)tmp->next->data] = '1';
	if (!valid_path(*path, end_index))
		delete_lst(path);
	*path = new_path;
	return (*(size_t *)tmp->data);
}

void		compute_paths_and_costs(t_master *lem_in)
{
	t_stack *queue;
	t_list	*path;
	size_t  current_node;
	char    *visited;
	char	start;

	queue = NULL;
	path = NULL;
	start = 1;
	current_node = lem_in->start_index;
	visited = ft_create_padding('0', lem_in->room_count);
	while (start || queue)
	{
		start = 0;
		while (add_adj_nodes_to_queue(lem_in, current_node, visited, &queue))
		{
			ft_lstaddend(&path, ft_lstnew(&current_node, sizeof(size_t)));
			current_node = pop_off_queue(&queue);
			printf("current_node is [%zu]\n", current_node);
			printf("visited (%s)\n", visited);
		}
		ft_lstaddend(&path, ft_lstnew(&current_node, sizeof(size_t)));
		if (valid_path(path, lem_in->end_index))
			add_to_path_lst(lem_in, &path);
		print_queue(&queue);
		current_node = backtrack_to_queued(&path, &queue, &visited, lem_in->end_index);
	}
	display_paths(lem_in);
	// free(visited);
}