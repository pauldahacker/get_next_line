/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:34 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/31 11:53:43 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*getbufferline(char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i++] == NEWLINE)
			break ;
	}
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i] = 0;
	while (--i >= 0)
		ret[i] = s[i];
	return (ret);
}

static int	myread(int fd, char *buf)
{
	int	readbytes;

	if (!buf)
		return (-1);
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (readbytes >= 0)
		buf[readbytes] = 0;
	return (readbytes);
}

char	*destroy(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

static char	*assemble(int fd, char *buf, int readbytes)
{
	char	*current;
	char	*joined;

	current = getbufferline(buf);
	if (!current)
		return (NULL);
	joined = ft_strdup(current);
	if (!joined)
		return (destroy(&current));
	while (!ft_strchr(joined, NEWLINE) && readbytes)
	{
		destroy(&current);
		readbytes = myread(fd, buf);
		if (readbytes == -1)
			return (destroy(&joined));
		current = getbufferline(buf);
		if (!current)
			return (destroy(&joined));
		joined = ft_strjoin(joined, current);
		if (!joined)
			return (destroy(&current));
	}
	destroy(&current);
	return (joined);
}

char	*get_next_line(int fd)
{
	static char	*buf[FD_LIMIT];
	char		*joined;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = BYTE_START;
	if (!buf[fd])
	{
		buf[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf[fd])
			return (NULL);
		readbytes = myread(fd, buf[fd]);
		if (readbytes <= 0)
			return (destroy(&(buf[fd])));
	}
	joined = assemble(fd, buf[fd], readbytes);
	if (!joined)
		return (destroy(&(buf[fd])));
	buf[fd] = tochr(buf[fd], NEWLINE);
	return (joined);
}
