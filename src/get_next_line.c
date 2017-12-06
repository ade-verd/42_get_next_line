/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/06 15:16:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_lstappend(t_fd *newd, t_fd *fd)
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

static int		ft_read_fd(const int fd, t_fd *1st_link)
{
	int		i;
	char	*buf[BUFF_SIZE + 1];
	char	*str;
	int		len;
	t_fd	*new_fd;

	i = 0;
	len = 0;
	new_fd->fd = fd;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		len = len + BUFF_SIZE;
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (-1);
		buf[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buf);
		free(buf);
	}
	if (ret == -1)
		return (-1);
	new_fd->str = str;
	new_fd->to_read = str;
	ft_lstappend(new_fd, 1st_link);
	return (1);
}

static char		*ft_seek_link_str(int fd, t_fd *files)
{
	while (files)
	{
		if (files->fd == fd)
			return (files->str);
		files = files->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd	*files;

	if (!files)
		files = NULL;
	if (!fd || !line)
		return (-1);
	if (!ft_seek_link_str(fd, files))
	{
		if (ft_read_fd(fd, files) == 1)
			printf("fd creation !\tstr:\n\n%s\n", tmp->str);
	}
	printf("fd already exists !\tstr:\n\n%s\n", tmp->str);
	return (1);
}
