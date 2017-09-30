/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:56:29 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/30 12:10:32 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_error_and_kill(char error_code)
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
