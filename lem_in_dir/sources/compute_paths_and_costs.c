/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_paths_and_costs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:01:26 by lramirez          #+#    #+#             */
/*   Updated: 2017/10/13 12:41:00 by lramirez         ###   ########.fr       */
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
		printf("\n (%s) ", path->visited);
		printf("	costs (%zu) ", path->cost);
		print_path(path->itin);
		printf("	last node == [%zu]\n", path->last_node);
		path = path->next;
		count++;
	}
}

void		display_paths(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;
	t_list	*path_lst;

	i = 1;
	path_lst = lem_in->all_paths;
	printf("\n ALL POSSIBLE PATHS\n");
	while (path_lst)
	{
		tmp = ((t_path *)path_lst->data)->itin;
		printf("\n ** path %zu ** ", i);
		printf("	costs (%zu) moves: ", ((t_path *)path_lst->data)->cost);
		while (tmp->next)
		{
			printf(" [%zu] -->", *(size_t *)tmp->data);
			tmp = tmp->next;
		}
		printf(" [%zu]\n\n", *(size_t *)tmp->data);
		path_lst = path_lst->next;
		i++;
	}
}

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
		tmp->previous = path;
		queue->top = path;
		path->next = tmp;
	}
	queue->size++;
}

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
			new_path->last_node = current_node;
			new_path->cost = ft_lstlen(new_path->itin) - 1;
			new_path->next = NULL;
			new_path->previous = NULL;
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

void		free_path(t_path **path)
{
	t_list	*tmp;
	t_list	*tmp_next;

	tmp = (*path)->itin;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free((*path)->visited);
	free(*path);
	*path = NULL;
}

void		pop_off_bottom_queue(t_stack *queue)
{
	t_path		*tmp;

	tmp = queue->bottom;
	queue->bottom = tmp->previous;
	tmp->previous->next = NULL;
	free_path(&tmp);
	queue->size--;
}

void		move_to_path_lst(t_master *lem_in, t_stack *queue)
{
	t_path		*tmp;

	ft_lstaddend(&lem_in->all_paths, ft_lstnew(queue->bottom, sizeof(t_path)));
	tmp = queue->bottom;
	queue->bottom = tmp->previous;
	tmp->next = NULL;
	queue->size--;
}

void		initialize_find_paths(t_path **current_path,
				t_stack **queue, size_t room_count)
{
	*current_path = (t_path *)ft_memalloc(sizeof(t_path));
	(*current_path)->itin = NULL;
	(*current_path)->visited = ft_create_padding('0', room_count);
	(*current_path)->cost = 0;
	(*current_path)->next = NULL;
	(*current_path)->previous = NULL;
	*queue = (t_stack *)ft_memalloc(sizeof(t_stack));
	(*queue)->bottom = NULL;
	(*queue)->top = NULL;
	(*queue)->size = 0;
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
			// if (queue->bottom->cost < lem_in->ant_count || !lem_in->all_paths)
				queue_possible_paths(lem_in, current_node, queue->bottom, queue);
			pop_off_bottom_queue(queue);
		}
		else
			move_to_path_lst(lem_in, queue);
	}
	display_paths(lem_in);
}
