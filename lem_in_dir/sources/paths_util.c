/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:07:11 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/13 11:48:14 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_path(t_path **path)
{
	t_list	*tmp;

	while ((*path)->itin)
	{
		tmp = (*path)->itin;
		(*path)->itin = (*path)->itin->next;
		free(tmp->data);
		tmp->data = NULL;
		free(tmp);
		tmp = NULL;
	}
	free((*path)->visited);
	(*path)->visited = NULL;
	free(*path);
	*path = NULL;
}

void		pop_off_bottom_queue(t_stack *queue, char to_free)
{
	t_path		*tmp;

	tmp = queue->bottom;
	queue->bottom = tmp->previous;
	if (queue->size > 1)
		tmp->previous->next = NULL;
	if (to_free)
		free_path(&tmp);
	tmp = NULL;
	queue->size--;
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

t_room		*add_path(t_master *lem_in)
{
	t_room	*new;
	t_room	*ret;
	t_list	*tmp;

	tmp = ((t_path *)lem_in->all_paths->data)->itin->next;
	new = (t_room *)ft_memalloc(sizeof(t_room));
	ret = new;
	new->received_ant = 0;
	new->index = (size_t)tmp->data;
	tmp = tmp->next;
	while (tmp)
	{
		new->next = (t_room *)ft_memalloc(sizeof(t_room));
		new->next->next = NULL;
		new->next->received_ant = 0;
		new->next->index = (size_t)tmp->data;
		new = new->next;
		tmp = tmp->next;
	}
	return (ret);
}

void		move_to_path_lst(t_master *lem_in, t_stack *queue)
{
	ft_lstaddend(&lem_in->all_paths, ft_lstnew(queue->bottom, sizeof(t_path)));
	pop_off_bottom_queue(queue, 1);
}
