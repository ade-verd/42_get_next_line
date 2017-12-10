/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/10 17:15:35 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_open_file(char *path, int flags)
{
	int		fd;

	fd = open(path, flags);
	if (fd == -1)
	{
		ft_putstr_fd("open() error\n", 2);
		return (-1);
	}
	return (fd);
}

int		ft_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() error\n", 2);
		return (-1);
	}
	return (1);
}

void	ft_display_all_fd(fd)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
		{
			printf("get_next_line() error\n");
			return ;
		}
		printf("fd:%d\tline: %d\t\t%-30s\treturn: %d\n", fd, i, line, ret);
		ft_memdel((void**)&line);
		i++;
	}
	printf("line: %d\t\t%-30s\treturn: %d\n", i, line, ret);
}

/*int		ft_two_fd(int fd1, int fd2)
{
	
}*/

int		main(int ac, char **av)
{
	int		fd1;
	int		fd2;

	if (ac >= 2)
	{
		if ((fd1 = ft_open_file(av[1], O_RDONLY)) == -1)
			return (-1);
		if ((fd2 = ft_open_file(av[2], O_RDONLY)) == -1)
			return (-1);
		ft_display_all_fd(fd1);
		ft_putstr("-------\n");
		ft_display_all_fd(fd2);
		ft_putstr("-------\n");
		ft_display_all_fd(fd1);
		ft_putstr("-------\n");
	if (ft_close(fd1) == -1 || ft_close(fd2) == -1)
		return (-1);
	}
	return (0);
}
