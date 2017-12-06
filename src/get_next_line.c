/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/06 18:40:03 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static void		ft_lstappend(t_fd *new, t_fd *fd)
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
}*/

static int		ft_read_fd(const int fd, t_fd *first_link)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		len;
	t_fd	*new_fd;

	len = 0;
	tmp = malloc(1);
	if (!(new_fd = (t_fd*)malloc(sizeof(t_fd))))
		return (-1);
	new_fd->fd = fd;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[BUFF_SIZE] = '\0';
		len = len + BUFF_SIZE;
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (-1);
		str = ft_strjoin(tmp, buf);
		ft_memdel((void**)&tmp);
		if (!(tmp = (char*)malloc(sizeof(char) * len +1)))
			return (-1);
		ft_strcpy(tmp, str);
		ft_memdel((void**)&str);
	}
	if (ret == -1)
		return (-1);
	printf("%s\n", tmp);
	new_fd->str = tmp;
	new_fd->to_read = tmp;
	ft_memdel((void**)&tmp);
	if (first_link != NULL)
		ft_lstadd(first_link, new_fd);
	else
	{
		first_link->fd = new_fd->fd;
		first_link->str = new_fd->str;
		first_link->to_read = new_fd->to_read;
		first_link->next = NULL;
	}
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

// utiliser ft_memccpy(void *dst, void *src, int c, site_t n)

int		get_next_line(const int fd, char **line)
{
	static t_fd	*files;
	char		*str;

	if (!files)
		files = NULL;
	if (!fd || !line)
		return (-1);
	if (!(str = ft_seek_link_str(fd, files)))
	{
		if (ft_read_fd(fd, files) == 1)
		{
			str = ft_seek_link_str(fd, files);
			printf("fd creation !\tstr:\n\n%s\n", str);
			return (1);
		}
	}
	printf("fd already exists !\tstr:\n\n%s\n", str);
	return (1);
}
