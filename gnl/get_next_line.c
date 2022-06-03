/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:01:20 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/29 15:01:23 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_findbreak(int fd, char **line, char **s, int i)
{
	char	*tmp;

	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i = i + 1;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup((s[fd]) + i + 1);
		ft_strdel(&s[fd]);
		if (!tmp || !line)
		{
			if (!line)
				free(tmp);
			return (-1);
		}
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

static int	ft_returnvalue(int ret, int fd, char **line, char **s)
{
	if (ret < 0)
	{
		if (s[fd])
			ft_strdel(&s[fd]);
		return (-1);
	}
	if (!ret && !s[fd])
		return (0);
	return (ft_findbreak(fd, line, s, 0));
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s[4096];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd > 4095)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 1)
			break ;
		buf[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			ft_strdel(&s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_returnvalue(ret, fd, line, s));
}
