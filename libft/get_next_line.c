/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:11:32 by ichemenc          #+#    #+#             */
/*   Updated: 2016/11/29 18:23:53 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_strbuf(char *str, char **buff, char **line)
{
	char *re;
	char *po;
	char *del1;

	del1 = *line;
	if ((re = ft_strchr(str, '\n')) != NULL)
	{
		po = re;
		po++;
		*buff = ft_strdup(po);
		*re = '\0';
	}
	*line = ft_strjoin(del1, str);
	free(del1);
	if (re != NULL)
		return (1);
	return (0);
}

static int		ft_return(char **line, char **buff, int b)
{
	if (ft_strlen(*line))
	{
		ft_memdel((void*)buff);
		return (1);
	}
	if (b == 0)
		return (0);
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	int				b;
	unsigned int	i;
	static char		*buff[MAX_FD];

	if (fd < 0 || BUFF_SIZE < 0 || line == NULL || fd > MAX_FD)
		return (-1);
	*line = ft_strnew(0);
	if ((buff[fd] = ft_strjoin(buff[fd], *line)) != NULL)
		if (1 == (i = ft_strbuf(buff[fd], &buff[fd], line)))
			return (1);
	buff[fd] = ft_strnew(BUFF_SIZE);
	while ((b = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][b] = '\0';
		if (1 == (i = ft_strbuf(buff[fd], &buff[fd], line)))
			return (1);
	}
	if (b == -1)
		return (-1);
	return (ft_return(line, &buff[fd], b));
}
