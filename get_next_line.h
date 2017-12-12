/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:15:05 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/12 11:46:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# include <stdio.h> // A SUPPRIMER printf

# define BUFF_SIZE 4
# define EXIST_INT(x) if (!x) return (-1);
# define EXIST_NULL(x) if (!x) return (NULL);

typedef struct	s_fd
{
	int			fd;
	char		*rest;
	void		*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
