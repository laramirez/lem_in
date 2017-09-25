/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:16:45 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/15 15:01:48 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	gnl_fd_2(t_fd *fd_element, char **line, char sep, ssize_t read_ret)
{
	char			*seek;
	char			*tmp;

	if (read_ret == 0 && **line == '\0')
	{
		ft_strdel(line);
		return (0);
	}
	if (read_ret == -1)
	{
		ft_strdel(line);
		return (-1);
	}
	if (ft_strchr(*line, sep))
	{
		seek = *line;
		while (*seek != sep && *seek)
			seek++;
		tmp = *line;
		*line = ft_strsub(*line, 0, seek - tmp);
		seek += 1;
		fd_element->stock = ft_strdup(seek);
		ft_strdel(&tmp);
	}
	return (1);
}

static int	gnl_fd_1(t_fd *fd_element, char **line, char sep)
{
	ssize_t			read_ret;
	char			*buffer;
	char			*tmp;

	if (fd_element->stock)
	{
		*line = ft_strsub(fd_element->stock, 0, ft_strlen(fd_element->stock));
		ft_strdel(&(fd_element->stock));
	}
	else
		*line = ft_strnew(0);
	buffer = ft_strnew(GNL_BUFF_SIZE);
	while (!ft_strchr(*line, sep) &&
		((read_ret = read(fd_element->fd, buffer, GNL_BUFF_SIZE)) > 0))
	{
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		ft_strdel(&tmp);
		ft_strclr(buffer);
	}
	ft_strdel(&buffer);
	return (gnl_fd_2(fd_element, line, sep, read_ret));
}

static t_fd	*add_to_list(t_fd **fd_list, int fd)
{
	t_fd	*tmp;

	tmp = *fd_list;
	if (!tmp)
	{
		tmp = (t_fd *)ft_memalloc(sizeof(t_fd));
		tmp->fd = fd;
		tmp->stock = NULL;
		tmp->next = NULL;
		*fd_list = tmp;
		return (*fd_list);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_fd *)ft_memalloc(sizeof(t_fd));
	tmp->next->fd = fd;
	tmp->next->stock = NULL;
	tmp->next->next = NULL;
	return (tmp->next);
}

static int	gnl_separator(const int fd, char **line, char sep)
{
	static t_fd		*fd_list;
	t_fd			*seek;

	seek = fd_list;
	while (seek)
	{
		if (seek->fd == fd)
			return (gnl_fd_1(seek, line, sep));
		seek = seek->next;
	}
	return (gnl_fd_1(add_to_list(&fd_list, fd), line, sep));
}

int			get_next_line(const int fd, char **line)
{
	if (GNL_BUFF_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	return (gnl_separator(fd, line, GNL_SEPARATOR));
}
