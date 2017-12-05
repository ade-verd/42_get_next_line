/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/05 18:56:46 by ade-verd         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	if (ac == 2)
	{
		if ((fd = ft_open_file(av[1], O_RDONLY)) == -1)
			return (-1);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (ret == -1)
				printf("get_next_line() error\n");
			printf("return: %-5d\tline: %s\n", ret, line)
		}
	}
	return (0);
}
