/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/23 08:56:43 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** get_next_line
** Extracts a line from fd.
** A line is ended by '\n' or EOF (End Of File)
**
** Return
** (1) A line is read | (0) Reading is over | (-1) Error
*/

static t_list	*ft_check_fd(t_list **begin, int fd)
{
	t_list	*file;

	file = *begin;
	while (file)
	{
		if (fd == (int)file->content_size)
			return (file);
		file = file->next;
	}
	file = ft_lstnew("\0", 1);
	file->content_size = fd;
	ft_lstadd(begin, file);
	return (file);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*f;
	t_list			*begin;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	begin = f;
	f = ft_check_fd(&begin, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!ft_memchr(f->content, '\n', ft_strlen(f->content) + 1)
			&& (ret = read(fd, buf, BUFF_SIZE)))
		MALLCHECK((f->content = ft_strnjoinfree(f->content, buf, ret, 0)));
	ret = 0;
	while (((char *)f->content)[ret] && ((char *)f->content)[ret] != '\n')
		++ret;
	MALLCHECK((*line = ft_strndup(f->content, ret)));
	(((char *)f->content)[ret] == '\n') ? ++ret : 0;
	tmp = f->content;
	MALLCHECK((f->content = ft_strdup(f->content + ret)));
	free(tmp);
	f = begin;
	return (ret ? 1 : 0);
}
