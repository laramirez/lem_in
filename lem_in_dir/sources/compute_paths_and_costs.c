/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_paths_and_costs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/07 23:00:18 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_queue(t_stack *queue)
{
	t_path	*path;
	size_t	count;

	path = queue->top;
	count = 1;
	while (path)
	{
		printf("\n ** path %zu ** ", count);
		printf("	costs (%zu) moves: ", path->cost);
		print_path(path->itin);
		path = path->next;
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

void		pile_onto_stack(t_path *path, t_stack *queue)
{
	t_path	*tmp;

	if (!queue->size)
	{
		queue->top = path;
		queue->bottom = path;
	}
	else
	{
		tmp = queue->top;
		queue->top = path;
		path->next = tmp;
	}
	queue->size++;
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

t_list		*add_current_node(t_path *current_path, size_t current_node)
{
	t_list	*new_itin;
	t_list	*scan;

	new_itin = NULL;
	scan = current_path->itin;
	while (scan)
	{
		ft_lstaddend(&new_itin, ft_lstnew((size_t *)scan->data, sizeof(size_t)));
		scan = scan->next;
	}
	ft_lstaddend(&new_itin, ft_lstnew(&current_node, sizeof(size_t)));
	return (new_itin);
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
			new_path->cost = ft_lstlen(new_path->itin);
			new_path->next = NULL;
			pile_onto_stack(new_path, queue);
			count++;
		}
		tunnels = tunnels->next;
	}
	if (count)
		return (1);
	return (0);
}

void		print_path(t_list *itin)
{
	t_list	*scan;

	scan = itin;
	while (scan->next)
	{
		printf(" [%zu] -->", *(size_t *)scan->data);
		scan = scan->next;
	}
	printf(" [%zu]\n", *(size_t *)scan->data);
}

void		compute_paths_and_costs(t_master *lem_in, size_t start)
{
	size_t		current_node;
	t_path		*current_path;
	t_stack		*queue;
	
	current_node = start;
	current_path = (t_path *)ft_memalloc(sizeof(t_path));
	current_path->itin = NULL;
	current_path->visited = ft_create_padding('0', lem_in->room_count);
	current_path->cost = 0;
	current_path->next = NULL;
	queue = (t_stack *)ft_memalloc(sizeof(t_stack));
	queue->bottom = NULL;
	queue->top = NULL;
	queue->size = 0;
	ft_lstaddend(&current_path->itin, ft_lstnew(&current_node, sizeof(size_t)));
	(current_path->visited)[current_node] = '1';
	if (!queue_possible_paths(lem_in, current_node, current_path, queue))
		print_process_error_and_kill(0);
	while (queue)
	{
		queue_possible_paths(lem_in, current_node, current_path, queue)
	}
}