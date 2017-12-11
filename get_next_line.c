/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/11 13:20:49 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_lstappend(t_fd *new, t_fd *fd)
{
	t_fd	*current;

	if (fd && new)
	{
		current = fd;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}

static t_fd		*ft_fill_fd(int fd, t_fd **first_link, char **str)
{
	t_fd	*new_fd;

	if (!(new_fd = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	new_fd->fd = fd;
	new_fd->rest = *str;
	if (*first_link != NULL)
		ft_lstappend(new_fd, *first_link);
	else
	{
		*first_link = new_fd;
		(*first_link)->next = NULL;
	}
	return (new_fd);
}

static t_fd		*ft_read_fd(const int fd, t_fd **first_link)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		len;

	len = 0;
	str = (char*)ft_memalloc(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		len = len + ret;
		if (!(tmp = (char*)ft_memalloc(sizeof(char) * len + 1)))
			return (NULL);
		tmp = ft_strjoin(str, buf);
		ft_memdel((void**)&str);
		if (!(str = (char*)ft_memalloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_strcpy(str, tmp);
		ft_memdel((void**)&tmp);
	}
	if (ret == -1)
		return (NULL);
	return(ft_fill_fd(fd, first_link, &str));
}

static t_fd		*ft_seek_link(int fd, t_fd *files)
{
	while (files)
	{
		if (files->fd == fd)
			return (files);
		files = files->next;
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd	*files;
	t_fd		*match_fd;

	if (fd < 0 || !line)
		return (-1);
	if (!(match_fd = ft_seek_link(fd, files)))
	{
		if (!(match_fd = ft_read_fd(fd, &files)))
			return (-1);
	}
	if (ft_strlen(match_fd->rest) == 0)
	{
	//	match_fd->fd = 0;
	//	match_fd->rest = NULL;
	//	ft_memdel((void**)&match_fd);
		return (0);
	}
	if (!(*line = ft_strnew(sizeof(char) * ft_strlen(match_fd->rest))))
		return (-1);
	//printf("len: %lu\trest: %s\t", ft_strlen(match_fd->rest),match_fd->rest);
	if (!(match_fd->rest = (char*)ft_memccpy_src(*line, match_fd->rest, '\n', 
					ft_strlen(match_fd->rest) + 1)))
		return (-1);
	if (ft_strchr(*line, '\n'))
		*line = ft_strsub(*line, 0, ft_strlen(*line) - 1);
	//printf("line: %s\n", *line);
	if (ft_strchr(match_fd->rest, '\n'))
		return (1);
//	match_fd->fd = 0;
//	match_fd->rest = NULL;
	//ft_memdel((void**)&match_fd);
	//printf("line: %s\n", *line);
	return (1);
}
