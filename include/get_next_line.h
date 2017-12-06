/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:15:05 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/06 13:24:35 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE	32

typedef struct	s_tab
{
	int			fd;
	char		*str;
	char		*to_read;
	void		*next;
}				t_tab;

int		get_next_line(const int fd, char **line);

#endif
