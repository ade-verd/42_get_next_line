/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:45 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/05 18:56:47 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int		ft_readlinewidth(int fd)
{
	char	buff[BUFF_SIZE + 1];
	size_t	nbread;

	(void)ft_memset((void*)buff, '\0', (size_t)BUFF_SIZE);
	nbread = read(fd, (void*)buff, (size_t)BUFF_SIZE);
	if (nbread == -1 || nbread == 0)
		return (-1);
	buff[BUFF_SIZE] = '\0';
	return (ft_atoi(buff));

void	ft_read_n_printlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;

	if (!(buff = (char*)malloc(sizeof(*buff) * (linewidth + 1))))
		return ;
	(void)ft_memset((void*)buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void*)buff, linewidth)) != 0)
	{
		ft_putstr(buff);
		(void)ft_memset((void*)buff, 0, linewidth);
	}
	free(buff)
	return ;
}*/

static int	ft_linewidth(int fd, int start)
{
	
}

static int	ft_which_offset(int fd)
{
	
}

int		get_next_line(const int fd, char **line)
{
	static int	offset;

	offset = 0;
}
