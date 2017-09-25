/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:10:54 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/25 16:28:05 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		display_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

int			main(void)
{
	t_master	lem_in;
	t_list		*input;
	char		*line;

	lem_in.ant_count = 0;
	lem_in.rooms = NULL;
	lem_in.room_count = 0;
	lem_in.start_index = 0;
	lem_in.end_index = 0;
	lem_in.tunnels = NULL;
	lem_in.instructions = NULL;
	input = NULL;
	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_lstaddend(&input, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	display_list(input);
	// get_params(input, &lem_in);
	// printf("ant_count is %zu\n", lem_in.ant_count);
	// printf("room_count is %zu\n", lem_in.room_count);
	// printf("start_index is %zu\n", lem_in.start_index);
	// printf("end_index is %zu\n", lem_in.end_index);
	// generate_move_instructions(lem_in);
	// ft_printf("\n");
	// display_list(*lem_in.instructions);
	// free everything!
	return (0);
}
