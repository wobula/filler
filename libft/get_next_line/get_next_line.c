/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:26:56 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 21:17:58 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_read(const int fd, char **s)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	if ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = *s;
		*s = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		*exit;
	int			x;

	if (fd < 0 || fd > INT_MAX - 1 || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while ((exit = ft_strchr(str[fd], '\n')) == NULL)
	{
		if ((x = ft_read(fd, &str[fd])) < 0)
			return (-1);
		if (x == 0 && !exit)
		{
			if (str[fd][0] == '\0')
				return (0);
			*line = str[fd];
			str[fd] = NULL;
			return (1);
		}
	}
	*line = ft_strsub(str[fd], 0, exit - str[fd]);
	str[fd] = ft_strdup(exit + 1);
	return (1);
}
