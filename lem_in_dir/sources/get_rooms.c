/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:20:10 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/30 12:12:24 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		initialize_get_rooms(size_t *n, char *start, char *end)
{
	*n = 0;
	*start = 0;
	*end = 0;
}

void		index_start_end(char *start, char *end, t_master *lem_in, size_t *n)
{
	if (*start == 1)
	{
		lem_in->start_index = *n;
		*start = 2;
	}
	else if (*end == 1)
	{
		lem_in->end_index = *n;
		*end = 2;
	}
}

void		store_room(t_master *lem_in, char *data, size_t *n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ft_strsub(data, 0, ft_strchr(data, ' ') - data);
	while (i < lem_in->room_count)
	{
		if (ft_strequ(tmp, lem_in->rooms[i]))
			print_error_and_kill(4);
		i++;
	}
	lem_in->rooms[*n] = tmp;
	(*n)++;
}

void		param_check(char start, char end, t_list *input)
{
	if (start != 2 || end != 2)
		print_error_and_kill(3);
	if (!input)
		print_error_and_kill(4);
}

t_list		*get_rooms(t_list *input, t_master *lem_in)
{
	size_t	n;
	char	start;
	char	end;

	initialize_get_rooms(&n, &start, &end);
	while (input && !is_tunnel((char *)input->data))
	{
		if (ft_strequ("##start", (char *)input->data) &&
			start == 0 && is_room((char *)input->next->data))
			start = 1;
		else if (ft_strequ("##end", (char *)input->data) &&
			end == 0 && is_room((char *)input->next->data))
			end = 1;
		else if (is_room((char *)input->data))
		{
			index_start_end(&start, &end, lem_in, &n);
			store_room(lem_in, (char *)input->data, &n);
		}
		else if ((!is_comment((char *)input->data) &&
			!is_command((char *)input->data)))
			break ;
		input = input->next;
	}
	param_check(start, end, input);
	return (input);
}
