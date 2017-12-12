/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/12 19:09:48 by ade-verd         ###   ########.fr       */
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

	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		EXIST_NULL((tmp = ft_strjoin(str, buf)));
		ft_memdel((void**)&str);
		EXIST_NULL((str = ft_strdup(tmp)));
		ft_memdel((void**)&tmp);
	}
	if (ret == -1)
		return (NULL);
	return (ft_fill_fd(fd, first_link, &str));
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
	char		*tmp;
	int			len;

	len = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!(match_fd = ft_seek_link(fd, files)))
		EXIST_INT((match_fd = ft_read_fd(fd, &files)));
	if (!ft_strlen(match_fd->rest))
		return (0);
	while (match_fd->rest[len] && match_fd->rest[len] != '\n')
		len++;
	EXIST_INT((*line = ft_strsub(match_fd->rest, 0, len)));
	EXIST_INT((tmp = ft_strdup(match_fd->rest)));
	if (ft_strchr(tmp, '\n'))
	{
		ft_memdel((void**)&match_fd->rest);
		EXIST_INT((match_fd->rest = ft_strsub(ft_strchr(tmp, '\n') + 1, 0,
						ft_strlen(tmp))));
	}
	else
	{
		//ft_strclr(match_fd->rest);
		match_fd->rest = NULL;
		match_fd->fd = -1;
	}
	ft_memdel((void**)&tmp);
	return (1);
}
