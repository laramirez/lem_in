/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:21:19 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/18 16:59:43 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>
# include "../../libft/includes/libft.h"

/* This project is based upon the following key structures :
**
**	- An array of (char *) used to stock all room names
**
**	- An array of (t_list *) used to detail, for each room,
**	which rooms it's adjacent to (NB: rooms will be named by their
**	size_t index of first array)
**
**	- A list of the turn by turn instructions to move the ants
**	
**	- A master structure stocking all these
*/

typedef struct	s_master
{
	size_t			ant_count;
	char			**rooms;
	size_t			room_count;
	size_t			start_index;
	size_t			end_index;
	t_list			**tunnels;
	t_list			*instructions;
}				t_master;

/*
** Functions in lem_in.c
*/
void	get_params(t_list *input, t_master *lem_in);
char	is_number(char *str);
char	is_room(char *str);
char	is_comment(char *str);
char	is_command(char *str);
char	is_tunnel(char *str);
void	display_list(t_list *list);

#endif
