/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2018/02/13 11:48:14 by lararamirez      ###   ########.fr       */
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
		free(tmp->data);
		tmp->data = NULL;
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}

void		free_rooms(t_master *lem_in)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		ft_strdel(&lem_in->rooms[i]);
		i++;
	}
	free(lem_in->rooms);
	lem_in->rooms = NULL;
}

void		free_tunnels(t_master *lem_in)
{
	size_t	i;

	i = 0;
	while (i < lem_in->room_count)
	{
		free_list(&lem_in->tunnels[i]);
		lem_in->tunnels[i] = NULL;
		i++;
	}
	free(lem_in->tunnels);
	lem_in->tunnels = NULL;
}

void		free_paths(t_master *lem_in)
{
	t_list *tmp;
	
	while (lem_in->all_paths)
	{
		tmp = lem_in->all_paths;
		lem_in->all_paths = lem_in->all_paths->next;
		free_path((t_path **)&tmp->data);
		free(tmp);
		tmp = NULL;
	}
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
	lem_in->r_opt = 0;
	lem_in->t_opt = 0;
	lem_in->p_opt = 0;
	(*lst) = NULL;
	(*line) = NULL;
}

int			get_option(char *arg, t_master *lem_in)
{
	if (*arg != '-')
		return (0);
	arg++;
	if (!arg)
		return (0);
	while (*arg)
	{
		if (!(*arg == 'r') && !(*arg == 't') && !(*arg == 'p'))
			return (0);
		if (*arg == 'r')
			lem_in->r_opt = 1;
		else if (*arg == 't')
			lem_in->t_opt = 1;
		else if (*arg == 'p')
			lem_in->p_opt = 1;
		arg++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_master	lem_in;
	t_list		*lst;
	t_list		*ptr;
	char		*line;

	initialize_main(&lem_in, &lst, &line);
	if (argc > 2)
		print_usage_and_kill(0);
	else if (argc == 2 && !get_option(argv[1], &lem_in))
		print_usage_and_kill(1);
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
	if (!find_paths(&lem_in, lem_in.start_index))
	{
		free_list(&lst);
		free_paths(&lem_in);
		free_rooms(&lem_in);
		print_process_error_and_kill(0);
	}
	display_entry(&lst);
	ft_printf("\n");
	if (lem_in.r_opt)
		display_rooms(&lem_in);
	if (lem_in.t_opt)
		display_tunnels(&lem_in);
	if (lem_in.p_opt)
		display_paths(&lem_in);
	generate_and_display_instructions(&lem_in);
	free_rooms(&lem_in);
	free_list(&lst);
	free_paths(&lem_in);
	free_list(&lem_in.instructions);
	free_tunnels(&lem_in);
	return (0);
}
