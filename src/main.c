/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/07 19:12:04 by ade-verd         ###   ########.fr       */
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

void		ft_display_all_fd(char *path)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if ((fd = ft_open_file(path, O_RDONLY)) == -1)
	{
		ft_putstr_fd("open() error", 2);
		return ;
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
		{
			printf("get_next_line() error\n");
			return ;
		}
		printf("line: %d\t\t%-30s\treturn: %d\n", i, line, ret);
		ft_memdel((void**)&line);
		i++;
	}
	printf("line: %d\t\t%-30s\treturn: %d\n", i, line, ret);
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return ;
	}
}

/*int		ft_two_fd(int fd1, int fd2)
{
	
}*/

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac >= 2)
	{
		ft_display_all_fd(av[1]);
		ft_putstr("-------\n");
		ft_display_all_fd(av[2]);
		ft_putstr("-------\n");
		ft_display_all_fd(av[1]);
		ft_putstr("-------\n");
	}
	return (0);
}
