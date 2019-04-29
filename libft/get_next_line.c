/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:34:44 by elhampto          #+#    #+#             */
/*   Updated: 2019/04/28 21:31:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*line_print(char *str)
{
	int				glutton;
	char			*prodigal;

	glutton = 0;
	while (str && str[glutton] != '\0' && str[glutton] != '\n')
	{
		if (str[glutton] == '\n')
			break ;
		glutton++;
	}
	prodigal = ft_strsub(str, 0, glutton);
	return (prodigal);
}

static char				*new_str(char *str, char *sss)
{
	if (str && (ft_strchr(str, '\n')))
	{
		sss = ft_strchr(str, '\n') + 1;
		sss = ft_strdup(sss);
		free(str);
		str = sss;
	}
	else if (str && (ft_strchr(str, '\0')))
	{
		sss = ft_strchr(str, '\0');
		sss = ft_strdup(sss);
		free(str);
		str = sss;
	}
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static char		*purga[MAX_FD];
	char			*limbo;
	int				lustful;

	lustful = 0;
	ft_bzero(buffer, BUFF_SIZE);
	if (fd < 0 || line == NULL || fd >= MAX_FD || read(fd, buffer, 0) < 0)
		return (-1);
	while ((lustful = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!purga[fd])
			purga[fd] = ft_strnew(BUFF_SIZE);
		buffer[lustful] = '\0';
		limbo = ft_strjoin(purga[fd], buffer);
		free(purga[fd]);
		purga[fd] = limbo;
		ft_bzero(buffer, BUFF_SIZE);
	}
	if (purga[fd] && *purga[fd] == '\0')
		return (lustful);
	*line = line_print(purga[fd]);
	purga[fd] = new_str(purga[fd], limbo);
	return (1);
}
