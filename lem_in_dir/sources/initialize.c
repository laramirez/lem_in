/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:38:57 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/08 18:41:14 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void		init_queue(t_path *new_path)
{
	new_path->next = NULL;
	new_path->previous = NULL;
}
