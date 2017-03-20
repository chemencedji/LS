/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:08:27 by mihail            #+#    #+#             */
/*   Updated: 2017/01/24 20:32:40 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool		is_dir(const char *filename)
{
	struct stat buf;

	if (lstat(filename, &buf) == -1)
		errexit("lstat");
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

t_bool		is_dir_link(const char *filename)
{
	struct stat buf;

	if (lstat(filename, &buf) == -1)
		errexit("lstat");
	if (S_ISLNK(buf.st_mode))
	{
		if (stat(filename, &buf) == 0 && S_ISDIR(buf.st_mode))
			return (1);
	}
	return (0);
}

struct stat	get_stat(const char *filename)
{
	struct stat buf;

	if (lstat(filename, &buf) == -1)
		errexit("lstat");
	return (buf);
}

void		errexit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char		*ft_pathjoin(char *dirpath, char *dir)
{
	char *temp;

	if (dir[0] == '/')
		return (ft_strdup(dir));
	temp = ft_strjoin(dirpath, "/");
	dirpath = ft_strjoin(temp, dir);
	free(temp);
	return (dirpath);
}
