/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/14 10:43:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_fill_fd
** Creates a new link and fills it.
*/

static t_list		*ft_fill_fd(int fd, t_list **first_link, char **str)
{
	t_list	*new_fd;

	if (!(new_fd = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_fd->content_size = fd;
	new_fd->content = *str;
	if (*first_link != NULL)
		ft_lstappend(new_fd, *first_link);
	else
	{
		*first_link = new_fd;
		(*first_link)->next = NULL;
	}
	return (new_fd);
}

/*
** ft_read_fd
** Reads all fd's content
*/

static t_list		*ft_read_fd(const int fd, t_list **first_link)
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

/*
** ft_resize_content
** Checks if there is an other line to read.
** In case of '\n' in *str, free & fill match_fd->content with the next line.
*/

static int			ft_resize_content(t_list *match_fd, char **str)
{
	if (ft_strchr(*str, '\n'))
	{
		ft_memdel((void**)&match_fd->content);
		EXIST_INT((match_fd->content = ft_strsub(ft_strchr(*str, '\n') + 1, 0,
						ft_strlen(*str))));
	}
	else
		ft_strclr(match_fd->content);
	ft_strdel(str);
	return (1);
}

/*
** ft_seek_link
** Searches equivalent file descriptor in t_list files->content_size
*/

static t_list		*ft_seek_link(int fd, t_list *files)
{
	while (files)
	{
		if (files->content_size == (size_t)fd)
			return (files);
		files = files->next;
	}
	return (NULL);
}

/*
** get_next_line
** Extracts a line from fd.
** A line is ended by '\n' or EOF (End Of File)
**
** Return
** (1) A line is read | (0) Reading is over | (-1) Error
*/

int					get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*match_fd;
	char			*tmp;
	int				len;

	len = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (!(match_fd = ft_seek_link(fd, files)))
		EXIST_INT((match_fd = ft_read_fd(fd, &files)));
	if (!ft_strlen(match_fd->content))
	{
		match_fd->content_size = -1;
		*line = NULL;
		return (0);
	}
	tmp = match_fd->content;
	while (tmp[len] && tmp[len] != '\n')
		len++;
	EXIST_INT((*line = ft_strsub(match_fd->content, 0, len)));
	EXIST_INT((tmp = ft_strdup(match_fd->content)));
	ft_resize_content(match_fd, &tmp);
	return (1);
}
