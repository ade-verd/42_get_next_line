/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:13:43 by ade-verd          #+#    #+#             */
/*   Updated: 2017/11/28 13:40:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_strchr_pos(const char *s, int start, char c)
{
	int		i;

	i = 0;
	while (s[start + i] != '\0')
	{
		if (s[start + i] == c)
			return (start + i);
		i++;
	}
	return (start + i);
}

static int		ft_count_wds(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char		*ft_extract_wds(char const *s, int start, char c)
{
	int		i;
	int		end;
	char	*wd;

	i = 0;
	end = ft_strchr_pos(s, start, c) - 1;
	if ((wd = (char*)malloc(sizeof(char) * (end - start + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0' && start <= end)
	{
		wd[i] = s[start];
		start++;
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ft_count_wds(s, c) + 1)) == NULL)
		return (NULL);
	while (i < ft_count_wds(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		len = ft_strlen(ft_extract_wds(s, j, c));
		if ((tab[i] = (char*)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		tab[i] = ft_extract_wds(s, j, c);
		tab[i][len] = '\0';
		j = ft_strchr_pos(s, j, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
