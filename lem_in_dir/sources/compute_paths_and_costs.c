/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_paths_and_costs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/07 18:36:08 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_queue(t_stack **queue)
{
	t_path	*path;
	t_list	*scan;
	size_t	count;

	path = (*queue)->top;
	count = 0;
	while (path)
	{
		scan = path->path;
		while (scan)
		{
			printf("\n ** path %zu ** ", count);
			printf("	costs (%zu) moves: ", path->cost);
			while (scan->next)
			{
				printf(" [%zu] -->", *(size_t *)scan->data);
				scan = scan->next;
			}
			printf(" [%zu]\n\n", *(size_t *)scan->data);
		}
		scan = scan->next;
		count++;
	}
}

// void		display_paths(t_master *lem_in)
// {
// 	size_t	i;
// 	t_list	*tmp;
// 	t_list	*path_lst;

// 	i = 1;
// 	path_lst = lem_in->paths_lst;
// 	printf("\n ALL POSSIBLE PATHS\n");
// 	while (path_lst)
// 	{
// 		tmp = ((t_path *)path_lst->data)->itin;
// 		printf("\n ** path %zu ** ", i);
// 		printf("	costs (%zu) moves: ", ((t_path *)path_lst->data)->cost);
// 		while (tmp->next)
// 		{
// 			printf(" [%zu] -->", *(size_t *)tmp->data);
// 			tmp = tmp->next;
// 		}
// 		printf(" [%zu]\n\n", *(size_t *)tmp->data);
// 		path_lst = path_lst->next;
// 		i++;
// 	}
// }

void		pile_onto_stack(t_list **path, t_stack **queue)
{
	t_list	*scan;

	if (!(*queue)->size)
	{
		(*queue)->top = *path;
		(*queue)->bottom = *path;
	}
	else
	{
		scan = (*queue)->top;
		(*queue)->top = *path;
		(*path)->next = scan;
	}
	(*queue)->size++;
}

// void		add_to_path_lst(t_master *lem_in, t_list **path)
// {
// 	t_path	*new_path;
// 	t_path	*test;

// 	new_path = (t_path *)ft_memalloc(sizeof(t_path));
// 	new_path->itin = *path;
// 	new_path->cost = ft_lstlen(*path) - 1;
// 	ft_lstaddend(&lem_in->paths_lst, ft_lstnew(new_path, sizeof(t_path)));
// 	test = (t_path *)lem_in->paths_lst->data;
// }

// size_t		pop_off_queue(t_stack **queue)
// {
// 	t_stack		*to_free;
// 	size_t		ret;
	
// 	ret = (*queue)->room;
// 	to_free = *queue;
// 	*queue = (*queue)->next;
// 	free(to_free);
// 	return (ret);
// }

// char		valid_path(t_list *path, size_t end_index)
// {
// 	while (path->next)
// 		path = path->next;
// 	if (*(size_t *)path->data == end_index)
// 		return (1);
// 	return (0);
// }

// void		reset_visited(char **visited)
// {
// 	size_t	i;

// 	i = 0;
// 	while ((*visited)[i])
// 	{
// 		(*visited)[i] = '0';
// 		i++;
// 	}
// }

// void		delete_lst(t_list **path)
// {
// 	t_list	*tmp;
// 	t_list	*tmp_next;
	
// 	tmp = *path;
// 	while (tmp)
// 	{
// 		tmp_next = tmp->next;
// 		free(tmp);
// 		tmp = tmp_next;
// 	}
// 	*path = NULL;
// }

// size_t		backtrack_to_queued(t_list **path, t_stack **queue,
// 				char **visited, size_t end_index)
// {
// 	t_list	*new_path;
// 	t_list	*old_path;
// 	size_t	current_node;

// 	new_path = NULL;
// 	old_path = *path;
// 	reset_visited(visited);
// 	while (*(size_t *)old_path->data != (*queue)->previous_room)
// 	{
// 		ft_lstaddend(&new_path, ft_lstnew((size_t *)old_path->data, sizeof(size_t)));
// 		(*visited)[*(size_t *)old_path->data] = '1';
// 		old_path = old_path->next;
// 	}
// 	ft_lstaddend(&new_path, ft_lstnew((size_t *)old_path->data, sizeof(size_t)));
// 	(*visited)[*(size_t *)old_path->data] = '1';
// 	current_node = pop_off_queue(queue);
// 	ft_lstaddend(&new_path, ft_lstnew(&current_node, sizeof(size_t)));
// 	(*visited)[current_node] = '1';
// 	if (!valid_path(*path, end_index))
// 		delete_lst(path);
// 	*path = new_path;
// 	return (current_node);
// }

// char        adj_nodes(t_master *lem_in, size_t current_node, char *visited)
// {
// 	size_t	count;
// 	t_list	*tunnels;

// 	if (current_node == lem_in->end_index)
// 		return (0);
// 	count = 0;
// 	tunnels = lem_in->tunnels[current_node];
// 	while (tunnels)
// 	{
// 		if (visited[*(size_t *)tunnels->data] == '0')
// 			count++;
// 		tunnels = tunnels->next;
// 	}
// 	if (count)
// 		return (1);
// 	return (0);
// }

char		queue_possible_paths(t_master *lem_in, size_t current_node,
				t_path *current_path, t_stack **queue)
{
	t_list	*tunnels;
	t_list	*itin;
	t_path	*new_path;
	size_t	count;

	tunnels = lem_in->tunnels[current_node];
	count = 0;
	while (tunnels)
	{
		if ((*visited)[*(size_t *)tunnels->data] == '0')
		{
			new_path = path_dup(current_path);
			ft_lstaddend(&itin,
				ft_lstnew(*(size_t *)tunnels->data, sizeof(size_t)));
			pile_onto_stack(&path, queue);
			count++;
		}
		tunnels = tunnels->next;
	}
	if (count)
		return (1);
	return (0);
}

void		compute_paths_and_costs(t_master *lem_in, size_t start)
{
	size_t		current_node;
	t_path		*current_path;
	t_stack		queue;
	
	current_node = start;
	current_path = NULL;
	queue.bottom = NULL;
	queue.top = NULL;
	queue.size = 0;
	ft_lstaddend(&current_path, ft_lstnew(&current_node, sizeof(size_t)));
	(current_path->visited)[current_node] = '1';
	if (!queue_possible_paths(lem_in, current_node, current_path, &queue))
		print_process_error_and_kill(0);
	print_queue(&queue);
	// while (queue.size)
	// {
	// 	current_node =
	// 	queue_possible_paths;
	// 	if (bla bla bla)
	// 		abandon_path, next in line
	// }

	// while (add_possible_paths_to_queue(lem_in, current_node, &visited, &queue))
	// {
	// 	count--;
	// 	add_possible_paths_to_queue(lem_in, current_node, &visited, &queue);
	// 	current_node = pop_off_queue(&queue);
	// 	ft_lstaddend(&path, ft_lstnew(&current_node, sizeof(size_t)));
	// 	visited[current_node] = '1';
	// 	while (!adj_nodes(lem_in, current_node, visited))
    //     {
    //         if (current_node == lem_in->end_index)
    //             add_to_path_lst(lem_in, &path);
    //         if (queue)
	// 			current_node = backtrack_to_queued(&path, &queue, &visited, lem_in->end_index);
	// 		else if (!queue && current_node == start)
	// 			break ;
	// 	}
	// }
	// display_paths(lem_in);
	// free(visited);
}