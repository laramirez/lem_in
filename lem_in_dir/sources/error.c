/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:56:29 by lararamirez       #+#    #+#             */
/*   Updated: 2018/02/10 16:15:15 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_usage_and_kill(char error_code)
{
	if (error_code == 0)
		dprintf(2, "usage: ./lem-in [-[r][t][p]] < map");
	else if (error_code == 1)
	{
		dprintf(2, "available options: [r] display rooms | [t] display ");
		dprintf(2, "tunnels | [p] display paths\n");
	}
	exit(EXIT_FAILURE);
}

void	print_preprocess_error_and_kill(char error_code)
{
	if (error_code == 0)
		dprintf(2, "ERROR [requires parameters]");
	else if (error_code == 1)
		dprintf(2, "ERROR [first line of parameters must be valid ant count]");
	else if (error_code == 2)
		dprintf(2, "ERROR [requires more valid rooms to resolve]");
	else if (error_code == 3)
		dprintf(2, "ERROR [requires valid start and end parameters]");
	else if (error_code == 4)
		dprintf(2, "ERROR [requires more valid tunnels to resolve]");
	dprintf(2, " -- note: processing stops at first invalid line\n");
	exit(EXIT_FAILURE);
}

void	print_process_error_and_kill(char error_code)
{
	if (error_code == 0)
		dprintf(2, "ERROR [there is no way out, the ants are stuck forever!!]");
	dprintf(2, " -- note: you should feel really bad about this\n");
	exit(EXIT_FAILURE);
}

void	stop_input(t_list **previous, t_list **input)
{
	(*previous)->next = NULL;
	free_list(input);
}
