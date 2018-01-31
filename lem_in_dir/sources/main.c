/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2018/01/31 10:32:25 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		display_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%zu\n", *(size_t *)tmp->data);
		tmp = tmp->next;
	}
}

void		display_rooms(t_master *lem_in)
{
	size_t	i;

	i = 0;
	printf("\n ROOM INDEX\n\n");
	while (i < lem_in->room_count)
	{
		if (i == lem_in->start_index)
			printf("	[%zu] (room name: %s) *start\n", i, lem_in->rooms[i]);
		else if (i == lem_in->end_index)
			printf("	[%zu] (room name: %s) *end\n", i, lem_in->rooms[i]);
		else
			printf("	[%zu] (room name: %s)\n", i, lem_in->rooms[i]);
		i++;
	}
}

void		display_tunnels(t_master *lem_in)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	printf("\n TUNNELS INDEX\n\n");
	while (i < lem_in->room_count)
	{
		if (lem_in->tunnels[i])
		{
			tmp = lem_in->tunnels[i];
			printf("	[%zu] >", i);
			while (tmp->next)
			{
				printf(" [%zu] &", *(size_t *)tmp->data);
				tmp = tmp->next;
			}
			printf(" [%zu]\n", *(size_t *)tmp->data);
		}
		i++;
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
	(*lst) = NULL;
	(*line) = NULL;
}

void		display_entry(t_list **lst)
{
	while (*lst)
	{
		ft_printf("%s\n", (*lst)->data);
		(*lst) = (*lst)->next;
	}
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
		print_preprocess_error_and_kill(1);
	if (!count_rooms(lst->next, &lem_in))
		print_preprocess_error_and_kill(2);
	ptr = get_rooms(lst->next, &lem_in);
	get_tunnels(ptr, &lem_in);
	find_paths(&lem_in, lem_in.start_index);
	display_entry(&lst);
	ft_printf("\n");
	display_list(lem_in.instructions);
	// display_rooms(&lem_in);
	// display_tunnels(&lem_in);
	display_paths(&lem_in);
	generate_and_display_instructions(&lem_in);
	// free everything! (lst and lem_in and instr)
	return (0);
}
