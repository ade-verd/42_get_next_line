/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/12 19:09:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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

void	ft_display_all_fd(int fd)
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
		printf("line: %d\t\t%-30s\treturn: %d\n", i, line, ret);
		ft_memdel((void**)&line);
		i++;
	}
	printf("-----\n");
}

void	ft_display_altern_fd(int fd1, int fd2)
{
	char	*line1;
	char	*line2;
	int		ret1;
	int		ret2;
	int		i;

	i = 0;
	while ((ret1 = get_next_line(fd1, &line1)) == 1 &&
					(ret2 = get_next_line(fd2, &line2)) == 1)
	{
		printf("line: %d\t\treturn: %d\tfd: %d\t|%s|\n", i, ret1, fd1, line1);
		ft_memdel((void**)&line1);
		printf("line: %d\t\treturn: %d\tfd: %d\t|%s|\n", i, ret2, fd2, line2);
		ft_memdel((void**)&line2);
		i++;
	}
	while((ret2 = get_next_line(fd2, &line2) == 1))
	{
		printf("line: %d\t\treturn: %d\tfd: %d\t|%s|\n", i, ret2, fd2, line2);
		ft_memdel((void**)&line2);
		i++;
	}
}

void	ft_fucking_bastard_test(void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;
	int		diff_file_size;

	system("mkdir -p fd/sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > fd/sandbox/one_big_fat_line.txt");
	system("echo '\n' >> fd/sandbox/one_big_fat_line.txt");

	fd = open("fd/sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("fd/sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);
	system("diff fd/sandbox/one_big_fat_line.txt fd/sandbox/one_big_fat_line.txt.mine > fd/sandbox/one_big_fat_line.diff");
	fd3 = open("fd/sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);
	printf("diff\t%d\n", diff_file_size);
}

int		main(int ac, char **av)
{
	int		fd1;
//	int		fd2;

	if (ac >= 2)
	{
		if ((fd1 = ft_open_file(av[1], O_RDONLY)) == -1)
			return (-1);
	//	if ((fd2 = ft_open_file(av[2], O_RDONLY)) == -1)
	//		return (-1);
	//	ft_fucking_bastard_test();
		ft_display_all_fd(fd1);
	//	ft_display_all_fd(fd2);
	//	ft_display_all_fd(fd1);
//		ft_display_altern_fd(fd1, fd2);
//		if (ft_close(fd1) == -1 || ft_close(fd2) == -1)
		if (ft_close(fd1) == -1)
			return (-1);
	}
	return (0);
}
