/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/06 18:40:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*int		ft_display_all_fd(int fd)
{
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
		{
			printf("get_next_line() error\n");
			return (ret);
		}
		//printf("return: %-5d\tline: %-5d\t|%s|\n", ret, i, line);
		i++;
	}
	return (ret);
}*/

/*int		ft_two_fd(int fd1, int fd2)
{
	
}*/

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	if (ac == 2)
	{
		if ((fd = ft_open_file(av[1], O_RDONLY)) == -1)
			return (-1);
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			printf("get_next_line() error\n");
			return (-1);
		}
		//printf("return: %-5d\tline: %s\n", ret, line);
		if (close(fd) == -1)
		{
			ft_putstr_fd("close() error" ,2);
			return (-1);
		}
	}
	return (0);
}
