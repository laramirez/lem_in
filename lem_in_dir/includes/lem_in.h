/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:21:19 by lararamirez       #+#    #+#             */
/*   Updated: 2018/01/09 16:18:49 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../../libft/includes/libft.h"

/*
** This project is based upon the following key structures :
**	- An array of (char *) used to stock all room names
**	- An array of (t_list *) used to detail, for each room,
**	which rooms it's adjacent to (NB: rooms will be named by their
**	size_t index of first array)
**	- A list of the turn by turn instructions to move the ants
**	- A master structure stocking all these
*/

typedef struct	s_path
{
	t_list			*itin;
	size_t			last_node;
	char			*visited;
	size_t			cost;
	struct s_path	*next;
	struct s_path	*previous;
}				t_path;

typedef struct	s_stack
{
	t_path			*bottom;
	t_path			*top;
	size_t			size;
}				t_stack;

typedef struct	s_master
{
	size_t			ant_count;
	char			**rooms;
	size_t			room_count;
	size_t			start_index;
	size_t			end_index;
	t_list			**tunnels;
	t_list			*all_paths;
	t_list			*instructions;
}				t_master;

// typdef struct	s_ant
// {
// 	size_t			ID;
// 	size_t			current_room;
// }				t_ant;


/*
** Functions in main.c
*/
void			initialize_main(t_master *lem_in, t_list **lst, char **line);
void			display_rooms(t_master *lem_in);
void			display_list(t_list *list);
void			display_tunnels(t_master *lem_in);
void			display_entry(t_list **lst);

/*
** Functions in get_rooms.c
*/
t_list			*get_rooms(t_list *input, t_master *lem_in);
void			initialize_get_rooms(size_t *n, char *start, char *end);
void			param_check(char start, char end, t_list *input);
void			store_room(t_master *lem_in, char *data, size_t *n);
void			index_start_end(char *start, char *end,
				t_master *lem_in, size_t *n);

/*
** Functions in get_tunnels.c
*/
void			get_tunnels(t_list *input, t_master *lem_in);
size_t			get_room_index(t_master *lem_in, char *data);
char			store_tunnel(t_master *lem_in, char *data);
char			add_to_list_at_index(t_master *lem_in,
					char *adjacent_room, size_t i);
char			not_duplicate_tunnel(t_list *tunnel_lst, size_t i);

/*
** Functions in compute_paths_and_costs.c
*/
void			find_paths(t_master *lem_in, size_t start);
void			initialize_find_paths(t_path **current_path,
					t_stack **queue, size_t room_count);
void			print_path(t_list *itin);
char			queue_possible_paths(t_master *lem_in, size_t current_node,
					t_path *current_path, t_stack *queue);
t_list			*add_current_node(t_path *current_path, size_t current_node);
void			pile_onto_stack(t_path *path, t_stack *queue);
char			*fill_visited(t_path *path, size_t room_count);
void			print_queue(t_stack *queue);
void			free_path(t_path **path);
void			move_to_path_lst(t_master *lem_in, t_stack *queue);
void			pop_off_bottom_queue(t_stack *queue);
void			display_paths(t_master *lem_in);
void			generate_and_display_instructions(t_master *lem_in);


/*
** Functions in tools.c
*/
char			is_number(char *str);
char			is_room(char *str);
char			is_comment(char *str);
char			is_command(char *str);
char			is_tunnel(char *str);

/*
** Functions in other.c
*/
char			check_coordinates(char *str);
char			get_ant_count(char *data, t_master *lem_in);
char			not_duplicate_room(t_list *room, char *name);
size_t			get_index(t_master *lem_in, char *name);
char			count_rooms(t_list *input, t_master *lem_in);

/*
** Functions in error.c
*/
void			print_preprocess_error_and_kill(char error_code);
void			print_process_error_and_kill(char error_code);


#endif
