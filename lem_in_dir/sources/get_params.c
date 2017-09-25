/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:20:10 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/25 16:29:12 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	count_rooms(t_list *input, t_master *lem_in)
{
	while (input)
	{
		if (is_room(input->content))
			lem_in->room_count++;
		else if (is_tunnel(input->content) || !ft_strlen(input->content) ||
			((char *)(input->content))[0] == 'L')
			break;
		input = input->next;		
	}
	if (lem_in->room_count == 0)
		ft_kill();
	lem_in->rooms = (char **)ft_memalloc(sizeof(char *) * lem_in->room_count);
}

size_t	get_index(t_master *lem_in, char *name)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		if (ft_strequ(lem_in->rooms[i], name))
		{
			free(name);
			return (i);
		}
		i++;
	}
	free(name);
	return (0);
}

char	not_duplicate(t_list *room, char *name)
{
	while (room)
	{
		if (ft_strequ(name, (char *)room->content))
			return (0);
		room = room->next;
	}
	return (1);
}

void	get_ant_count(char *content, t_master *lem_in)
{
	long	ant_count;
	
	if (is_number(content) && (ant_count = ft_atoi(content)) >= 0 &&
		ant_count <= LONG_MAX)
		lem_in->ant_count = (size_t)ant_count;
	else
		ft_kill();
}

char	get_start_end(char *param)
{
	if (!*param)
		*param = 1;
	else
		return (0);
	return (1);
}

void	get_params(t_list *input, t_master *lem_in)
{
	size_t	n;
	char	*ptr;
	char	start;
	char	end;

	start = 0;
	end = 0;
	n = 0;
	get_ant_count((char *)input->content, lem_in);
	input = input->next;
	count_rooms(input, lem_in);
	while (input && !is_tunnel((char *)input->content))
	{
		if (ft_strequ("##start", (char *)input->content))
		{
			if (!get_start_end(&start))
				return ;
		}
		else if (ft_strequ("##end", (char *)input->content))
		{
			if (!get_start_end(&end))
				return ;
		}
		else if (is_room((char *)input->content))
		{
			if (start == 1)
			{
				lem_in->start_index = n;
				start = 2;
			}
			if (end == 1)
			{
				lem_in->end_index = n;
				end = 2;
			}
			lem_in->rooms[n] = ft_strsub((char *)input->content, 0,
				ft_strchr((char *)input->content, ' ') - (char *)input->content);
			n++;
		}
		else if (!is_comment((char *)input->content) &&
			!is_command((char *)input->content))
			return ;
		input = input->next;	
	}
	if (!start || !end || !input)
		ft_kill();
	lem_in->tunnels = (t_list **)ft_memalloc(sizeof(t_list *) *
		lem_in->room_count);
	while (input)
	{
		if (is_tunnel((char *)input->content))
		{
			ptr = ft_strchr((char *)input->content, '-');
			n = get_index(lem_in, ft_strsub((char *)input->content, 0,
				ptr - (char *)input->content));
			if (not_duplicate(lem_in->tunnels[n], ptr + 1))
				ft_lstaddend(&lem_in->tunnels[n], ft_lstnew(ft_strdup(ptr + 1),
					ft_strlen(ptr + 1) + 1));
		}
		else if (!is_comment((char *)input->content) && !is_command((char *)input->content))
			return ;
		input = input->next;
	}
}
