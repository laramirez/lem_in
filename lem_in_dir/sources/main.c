/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2018/02/09 17:19:24 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	tmp = NULL;
}

void		free_tunnels(t_master *lem_in)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		free_list(&(lem_in->tunnels[i]));
		i++;
	}
}

void		free_paths(t_list *all_paths)
{
	t_list *tmp;
	
	while (all_paths)
	{
		tmp = all_paths;
		all_paths = all_paths->next;
		free_path((t_path **)&tmp->data);
	}
	tmp->data = NULL;
}

void		initialize_main(t_master *lem_in, t_list **lst, char **line)
{
	lem_in->ant_count = 0;
	lem_in->rooms = NULL;
	lem_in->room_count = 0;
	lem_in->start_index = 0;
	lem_in->end_index = 0;
	lem_in->tunnels = NULL;
	lem_in->all_paths = NULL;
	lem_in->instructions = NULL;
	(*lst) = NULL;
	(*line) = NULL;
}

int			main(void)
{
	t_master	lem_in;
	t_list		*lst;
	t_list		*ptr;
	char		*line;

	initialize_main(&lem_in, &lst, &line);
	while (get_next_line(0, &line))
	{
		ft_lstaddend(&lst, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (!lst)
		print_preprocess_error_and_kill(0);
	if (!get_ant_count((char *)lst->data, &lem_in))
	{
		free_list(&lst);
		print_preprocess_error_and_kill(1);
	}
	if (!count_rooms(lst->next, &lem_in))
	{
		free_list(&lst);
		print_preprocess_error_and_kill(2);
	}
	ptr = get_rooms(lst->next, &lem_in);
	get_tunnels(ptr, &lem_in);
	find_paths(&lem_in, lem_in.start_index);
	display_entry(&lst);
	ft_printf("\n");
	// display_rooms(&lem_in);
	// display_tunnels(&lem_in);
	// display_paths(&lem_in);
	generate_and_display_instructions(&lem_in);
	free_list(&lst);
	while (1)
	{
		
	}
	// free_paths(lem_in.all_paths);
	// free_list(&lem_in.instructions);
	// free_tunnels(&lem_in);
	
	return (0);
}
